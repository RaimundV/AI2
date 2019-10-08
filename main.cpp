#include <iostream>
#include <random>
#include <ctime>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>

// Step function for all kinds of inputs and weight values
int StepFunction(std::vector <double> X, std::vector <double> w, double w0)
{
    double pwr = w0;
    int size = X.size();
    for (int i = 0; i < size; i++)
    {
        pwr += X[i] * w[i];
    }

    if (pwr >= 0)
        return 1;

    return -1;
}

// Sigmoid function for all kinds of inputs and weight values
double SigmoidFunction(std::vector <double> X, std::vector <double> w, double w0)
{
    double pwr = w0;
    int size = X.size();
    for (int i = 0; i < size; i++)
    {
        pwr += X[i] * w[i];
    }

    return ((2 / ( 1 + exp( (pwr * -1) ) )) - 1 );
}

double perceptronStep(std::vector < std::vector <double> > X, std::vector <double> w, double w0, double t[])
{
    double Ew;
    double classValue = 0;
    int c = 0;
    double mi = 0.1;
    int counter = 0;
    int limit = 10000;
    int size  = X.size();
    while (counter < limit)
    {
        Ew = 0;
        for (int i = 0; i < size; i++)
        {
            c = StepFunction(X[i], w, w0);

            for (int y = 0; y < w.size(); y++)
            {
                w[y] = w[y] + mi * (t[i] - c) * X[i][y];
            }
            w0 = w0 + mi * (t[i] - c);

            Ew += pow(t[i] - c, 2);
        }

        counter++;

        if ((Ew/2) <= classValue)
        {
            break;
        }

        if (limit == counter)
        {
            std::cout << "Limit of iterations reached" << std::endl;
        }
    }
    std::cout << "Optimal value found in " << counter << " steps" << std::endl;
    std::cout << "w0: " << w0;
    for (int y = 0; y < w.size(); y++)
    {
        std::cout << " w" << y << ": " << w[y];
    }

    std::cout << std::endl;
}

// Algorithm to find appropriate weight values based on the input vectors and t values
double perceptronSigmoid(std::vector < std::vector <double> > X, std::vector <double> w, double w0, double t[])
{
    double sigmoidValue;
    double Ew;
    double classValue = 0.001;
    double mi = 0.1;
    int counter = 0;
    int limit = 10000;
    int size  = X.size();
    while (counter < limit)
    {
        Ew = 0;
        for (int i = 0; i < size; i++)
        {
            sigmoidValue = SigmoidFunction(X[i], w, w0);

            for (int y = 0; y < w.size(); y++)
            {
                w[y] = w[y] + mi * (t[i] - sigmoidValue) * X[i][y];
            }
            w0 = w0 + mi * (t[i] - sigmoidValue);

            Ew += pow((t[i] - sigmoidValue),2);
        }

        counter++;

        if ((Ew/2) <= classValue)
        {
            break;
        }

        if (limit == counter)
        {
            std::cout << "Limit of iterations reached" << std::endl;
        }
    }
    std::cout << "Optimal value found in " << counter << " steps" << std::endl;
    std::cout << "Error value: " << Ew/2 << std::endl;
    std::cout << "w0: " << w0;
    for (int y = 0; y < w.size(); y++)
    {
        std::cout << " w" << y << ": " << w[y];
    }
    std::cout << std::endl;
}

// runs program with 1st task values
void runTask1()
{
    std::vector < std::vector <double> > X;
    X.push_back({1, 1});
    X.push_back({0, 1});
    X.push_back({1, 0});
    X.push_back({0, 0});
    std::vector <double> w = {0, 0};
    double w0 = 0;
    double t[] = {1, -1, -1, -1};

    std::cout << "Step function:" << std::endl;
    perceptronStep(X, w, w0, t);
    std::cout << "Sigmoid function:" << std::endl;
    perceptronSigmoid(X, w, w0, t);
}

// runs program with 2st task values
void runTask2()
{
    //Studento Nr.: S1712186 % 3 = 2

    std::vector < std::vector <double> > X;
    X.push_back({1, 1, 1});
    X.push_back({0, 1, 1});
    X.push_back({1, 0, 1});
    X.push_back({1, 1, 0});
    X.push_back({0, 1, 0});
    X.push_back({0, 0, 1});
    X.push_back({1, 0, 0});
    X.push_back({0, 0, 0});
    std::vector <double> w = {0,0,0};
    double w0 = 0;
    double t[] = {1, 1, 1, 1, 1, 1, 1, -1};

    std::cout << "Step function:" << std::endl;
    perceptronStep(X, w, w0, t);
    std::cout << "Sigmoid function:" << std::endl;
    perceptronSigmoid(X, w, w0, t);
}

// main method
int main()
{
    int input;
    std::cout << "run: " << std::endl;
    std::cout << "1. TASK 1:" << std::endl;
    std::cout << "2. TASK 2:" << std::endl;
    std::cout << "Choose a task number: ";
    std::cin >> input;
    std::cout << std::endl;

    switch (input)
    {
        case 1:
            std::cout << "TASK 1:" << std::endl;
            runTask1();
            break;
        case 2:
            std::cout << "TASK 2:" << std::endl;
            runTask2();
            break;
        default:
            std::cout << "No such task" << std::endl;
            break;
    }

    return 0;
}