#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>

const int GRID_SIZE = 20;
const int ANT = 1;
const int DOODLEBUG = 2;
const int ANT_NUMBER = 100;
const int DOODLEBUG_NUMBER = 5;

class Organism {
        int x, y;
        int stepsSinceLastBreed;
        int stepsSurvived;
        int type;
    public:
        Organism(int x, int y, int type) : x(x), y(y), type(type), stepsSinceLastBreed(0), stepsSurvived(0) {};

        virtual void move(std::vector<std::vector<Organism*>>& grid) = 0;
        virtual void breed(std::vector<std::vector<Organism*>>& grid) = 0;
        virtual void isStarved(std::vector<std::vector<Organism*>>& grid) {};

        void setX(int newX) {x = newX;};
        void setY(int newY) {y = newY;};
        void setStepsSinceLastBreed(int step) {stepsSinceLastBreed = step;};
        void setStepsSurvived(int step) {stepsSurvived = step;};
        void addStepsSinceLastBreed() {stepsSinceLastBreed += 1;};
        void addStepsSurvived() {stepsSurvived += 1;};
        
        int getX() {return x;};
        int getY() {return y;};
        int getType() {return type;};
        int getStepsSinceLastBreed() {return stepsSinceLastBreed;};
        int getStepsSurvived() {return stepsSurvived;};

        //Check empty spot around the critter
        bool canMove(int x, int y, std::vector<std::vector<Organism*>>& grid);

        //Flag the critter if it has moved in the current step
        bool isMoved = false;
};

bool Organism::canMove(int x, int y, std::vector<std::vector<Organism*>>& grid) {
    return x >=0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] == nullptr;
}

//Randomize a vector representing four directions
std::vector<int> randDir() {
    std::vector<int> directions = {0, 1, 2, 3};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(directions.begin(), directions.end(), g);

    return directions;
}

class Ant : public Organism {

        //Set to true when the ant is able to breed
        bool breedFlag;
    public:
        Ant(int x, int y) : Organism(x, y, ANT), breedFlag(true) {};

        virtual void move(std::vector<std::vector<Organism*>>& grid);
        virtual void breed(std::vector<std::vector<Organism*>>& grid);
};

void Ant::move(std::vector<std::vector<Organism*>>& grid) {
    int tempX = getX(), tempY = getY();
    switch (rand() % 4)
    {
        case 0: ++tempX; break;
        case 1: --tempX; break;
        case 2: ++tempY; break;
        case 3: --tempY; break;
    }
    if(canMove(tempX, tempY, grid)) {

        //If the randomized spot is empty, then the critter moves by swap
        std::swap(grid[getX()][getY()], grid[tempX][tempY]);
        setX(tempX);
        setY(tempY);
        isMoved = true;
    }
    if(getStepsSurvived() >= 3) breedFlag = true;
    addStepsSurvived();
    addStepsSinceLastBreed();
}

void Ant::breed(std::vector<std::vector<Organism*>>& grid) {
    if(getStepsSinceLastBreed() >= 3 && breedFlag) {
        std::vector<int> directions = randDir();
        for(int num : directions) {
            int tempX = getX(), tempY = getY();
            switch (num)
            {
                case 0: ++tempX; break;
                case 1: --tempX; break;
                case 2: ++tempY; break;
                case 3: --tempY; break;
            }
            if(canMove(tempX, tempY, grid)) {
                grid[tempX][tempY] = new Ant(tempX, tempY);
                breedFlag = false;
                setStepsSinceLastBreed(0);
                return;
            }
        }
    }
}

class Doodlebug : public Organism {
        int stepsSinceLastEat;
    public:
        Doodlebug(int x, int y) : Organism(x, y, DOODLEBUG), stepsSinceLastEat(0) {};

        virtual void move(std::vector<std::vector<Organism*>>& grid);
        virtual void breed(std::vector<std::vector<Organism*>>& grid);
        virtual void isStarved(std::vector<std::vector<Organism*>>& grid);

        int getStepsSinceLastEat() {return stepsSinceLastEat;};
};

void Doodlebug::move(std::vector<std::vector<Organism*>>& grid) {
    std::vector<int> directions = randDir();
    for(int num : directions)  {
        int tempX = getX(), tempY = getY();
        switch (num)
        {
            case 0: ++tempX; break;
            case 1: --tempX; break;
            case 2: ++tempY; break;
            case 3: --tempY; break;
        }
        if(tempX >= 0 && tempX < GRID_SIZE && tempY >= 0 && tempY < GRID_SIZE && grid[tempX][tempY] && grid[tempX][tempY]->getType() == ANT) {

            //Set the pointer of the ant to be eaten to nullptr
            grid[tempX][tempY] = nullptr;
            std::swap(grid[getX()][getY()], grid[tempX][tempY]);
            setX(tempX);
            setY(tempY);
            stepsSinceLastEat = 0;
            isMoved = true;
            addStepsSurvived();

            //If the critter breeds it no longer moves in the step, so return to main
            return;
        }
    }

    int tempX = getX(), tempY = getY();
    switch (rand() % 4)
    {
        case 0: ++tempX; break;
        case 1: --tempX; break;
        case 2: ++tempY; break;
        case 3: --tempY; break;
    }
    if(canMove(tempX, tempY, grid)) {
        std::swap(grid[getX()][getY()], grid[tempX][tempY]);
        setX(tempX);
        setY(tempY);
        isMoved = true;
    }
    addStepsSurvived();
    ++stepsSinceLastEat;
}

void Doodlebug::breed(std::vector<std::vector<Organism*>>& grid) {
    if(getStepsSurvived() >= 8 && getStepsSurvived() % 8 ==0) {
        std::vector<int> directions = randDir();
        for(int num : directions) {
            int tempX = getX(), tempY = getY();
            switch (num)
            {
                case 0: ++tempX; break;
                case 1: --tempX; break;
                case 2: ++tempY; break;
                case 3: --tempY; break;
            }
            if(canMove(tempX, tempY, grid)) {
                grid[tempX][tempY] = new Doodlebug(tempX, tempY);
                return;
            }
        }
    }
}

void Doodlebug::isStarved(std::vector<std::vector<Organism*>>& grid) {
    if(stepsSinceLastEat >= 3) {

        //Set the pointer to nullptr if it dies
        grid[getX()][getY()] = nullptr;
    }
}

std::vector<std::vector<Organism*>> generateGrid() {
    std::vector<std::vector<Organism*>> grid(GRID_SIZE, std::vector<Organism*>(GRID_SIZE, nullptr));

    int countAnts = 0, countDoodlebugs = 0;
    
    while(countAnts < ANT_NUMBER) {
        int x = rand() % GRID_SIZE, y = rand() % GRID_SIZE;
        if(!grid[x][y]) {
            grid[x][y] = new Ant(x, y);
            countAnts++;
        }
    }

    while(countDoodlebugs < DOODLEBUG_NUMBER) {
        int x = rand() % GRID_SIZE, y = rand() % GRID_SIZE;
        if(!grid[x][y]) {
            grid[x][y] = new Doodlebug(x, y);
            countDoodlebugs++;            
        }
    }

    return grid;
}

void printGrid(std::vector<std::vector<Organism*>>& grid) {
    for(int i = 0; i < GRID_SIZE; ++i) {
        for(int j = 0; j < GRID_SIZE; ++j) {
            if(grid[i][j] == nullptr) {
                std::cout << "- ";
            } else if (grid[i][j]->getType() == ANT) {
                std::cout << "o ";
            } else if (grid[i][j]->getType() == DOODLEBUG) {
                std::cout << "X ";
            } else {
                std::cout << "-";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int timeStep = 0;
    bool doodlebugExtinct = true, antExtinct = true;

    std::vector<std::vector<Organism*>> grid = generateGrid();

    while(true) {

        std::cout << "\nWorld at time " << timeStep + 1 << ": \n" << std::endl;
        printGrid(grid);

        for(int i = 0; i < GRID_SIZE; ++i) {
            for(int j = 0; j < GRID_SIZE; ++j) {
                if(grid[i][j] && grid[i][j]->getType() == DOODLEBUG && !grid[i][j]->isMoved) {
                    grid[i][j]->move(grid);
                    doodlebugExtinct = false;
                }
            }
        }

        for(int i = 0; i < GRID_SIZE; ++i) {
            for(int j = 0; j < GRID_SIZE; ++j) {
                if(grid[i][j] && grid[i][j]->getType() == ANT && !grid[i][j]->isMoved) {
                    grid[i][j]->move(grid);
                    antExtinct = false;
                }
            }
        }

        for(int i = 0; i < GRID_SIZE; ++i) {
            for(int j = 0; j < GRID_SIZE; ++j) {
                if(grid[i][j]) {
                    if(grid[i][j]->getType() == DOODLEBUG) {
                        grid[i][j]->isStarved(grid);
                        if(grid[i][j]){
                            grid[i][j]->breed(grid);
                            grid[i][j]->isMoved = false;
                            doodlebugExtinct = false;
                        }
                    } else if(grid[i][j]->getType() == ANT) {
                        grid[i][j]->breed(grid);
                        grid[i][j]->isMoved = false;
                        antExtinct = false;
                    }
                }
            }
        }   

        if(doodlebugExtinct) break;
        if(antExtinct) break;
        doodlebugExtinct = true;
        antExtinct = true;
        ++timeStep;

        std::cout << "\nPress ENTER to continue\n";
        std::cin.get();
    }

    return 0;
}