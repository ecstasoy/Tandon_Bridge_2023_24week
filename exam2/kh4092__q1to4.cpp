/*
Question 1:

 1. Base Case: When n = 1, 1 + 3^1 = (3^(1 + 1) - 1) / 2;
 2. Inductive Steps:
    1. Induction Hypothesis: When n = k, 1 + 3^1 + 3^2 + ... + 3^k = (3^(k + 1) - 1) / 2;
    2. Proof: 1 + 3^1 + 3^2 + ... + 3^k + 3^(k + 1)
            = (3^(k + 1) - 1) / 2 + 3^(k + 1) (Hypothesis)
            = 3^(k + 1) / 2 + 3^(k + 1) - 1 / 2
            = (3 / 2) * 3^(k + 1) - 1 / 2
            = (3^(k + 2) - 1) / 2
    3. Therefore, for n >= 0, 1 + 3 + 9 + 27 + ... + 3^n = (3^(n + 1) - 1) / 2.
*/

/*
Question 2:
a)
    1. Situation 1: Only Hal in the picture. We then choose the other four people for the rest of 7 people and it is a combination.
                    And there are C(7, 4) possibilities. Then the five people should be arrange in order and it's a permutation. 
                    There are another P(5, 5) possibilities. Therefore, there are C(8, 4)*P(5, 5) ways to be done if only Hal is in the picture.
                    C(7, 4)*P(5, 5) = 4200.

    2. Situation 2: Only Ida in the picture. It is the same as in situation 1.
                    Therefore, there are C(7, 4)*P(5, 5) = 4200 ways.

    There are 4200 + 4200 ways to take the picture if Hal or Ida are in the picture.

b) 
    We do not care about the order in sets, so we are going to use combination here. Give that 3 and 4 are already in the subset, 
    we should only choose 3 numbers from the rest of 8 numbers and it is C(8, 3) = 56. And of course an empty set is also a subset
    of S. So, there are 56 + 1 = 57 subsets of S.
*/

/*
Question 3:
a)
    Assume that event A: the first student is a freshman; B: the second student is a freshman.

    P(B | A) = P(B union A) / P(A)

        P(B union A) 
        = P(A) * C(9, 1) / C(29, 1)

    P(B | A) = C(9, 1) / C(29, 1) = 9! / 29!

b)
    Situation 1: 5 zeros and 3 ones. There are C(8, 5) = 56 ways;
    Situation 2: 6 zeros and 2 ones. There are C(8, 6) = 28 ways;
    Situation 3: 7 zeros and 1 ones, There are C(8, 7) = 8 ways;
    Situation 4: 8 zeros. There are C(8, 8) = 1 ways.

    Overall, there are 56 + 28 + 8 + 1 = 93 ways so that there are more zeros than ones.

    There are 2^8 ways in total.

    Therefore, the probability that the bit string has more zeros than ones is 93 / 2^8 = 93 / 256.
*/

/*
Question 4:

function 1:
    1. First nested loop: 
        outer loop runs in theta(log_5(n)) times;
        inner loop runs in theta(n) times;
        the loop runs tin theta(logn) * theta(n) times in total;

    2. Second nested loop (ignore the if statement):
        it clearly runs in theta(n^2) times.

    Therefore, the entire function runs in theta(logn) * theta(n) + theta(n^2) times, 
    SInce n^2 is the highest term, the time complexity should be theta(n^2).

function 2:
    The outer and inner loop both run in theta(log_5(n)) times;
    The nested loop runs in theta((logn)^2) times and the time complexity of the function is theta((logn)^2)
*/