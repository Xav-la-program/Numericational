#include <iostream>
#include "LinearCongruential.h"
#include "HeadTail.h"
#include "EcuyerCombined.h"
#include "Bernoulli.h"
#include "NormalBoxMuller.h"
#include "SinglePath.h"
#include "RandomProcess.h"
#include "BS1D.h"
#include "BSEULER1D.h"
#include "Milstein1D.h"
#include "EUCall.h"
#include "BSEulerND.h"
#include <Eigen/Dense>

#include <cmath>

//TEST

int main()
{

    //Eigen::MatrixXd A = Eigen::MatrixXd::Zero(2, 2);
    //std::cout << A << std::endl;

    //Eigen::MatrixXd m(2, 2);
    //m(0, 0) = 3;
    //m(1, 0) = 2.5;
    //m(0, 1) = -1;
    //m(1, 1) = m(1, 0) + m(0, 1);
    //std::cout << m << std::endl;
    
    LinearCongruential* Uniform_lc = new LinearCongruential(27, 17, 43, 100); //create ptr to LC generator
    EcuyerCombined* Uniform_ec = new EcuyerCombined();
    NormalBoxMuller* Normal_bm = new NormalBoxMuller(0, 1, Uniform_ec); 

    //std::cout << "LC gen" << std::endl;

    //for (int i=0; i<4; ++i)
    //{
    //    std::cout << Uniform_lc->Generate() << std::endl;
    //}

    //std::cout << "\n Mean LC = " << Uniform_lc->Mean(10000000) << std::endl; //0.395: not accurate (seed, m, c, a very important)
    //std::cout << "Variance LC = " << Uniform_lc->Variance(10000000) << std::endl;


    //std::cout << "\n EC gen" << std::endl;

    //for (int i=0; i<4; ++i)
    //{
    //    std::cout << Uniform_ec->Generate() << std::endl;
    //}

    //std::cout << "\n Mean EC = " << Uniform_ec->Mean(10000000) << std::endl;
    //std::cout << "Variance EC = " << Uniform_ec->Variance(10000000) << std::endl;

    //std::cout << "\n Normal BM gen" << std::endl;

    //for (int i=0; i<4; ++i)
    //{
    //    std::cout << Normal_bm->Generate() << std::endl;
    //}

    //std::cout << "\n Mean BM = " << Normal_bm->Mean(10000000) << std::endl;
    //std::cout << "Variance BM = " << Normal_bm->Variance(10000000) << std::endl;

    RandomGenerator* gen = Normal_bm;
    double S = 100.;
    double K = 100;
    double r = 0.;
    double vol = 0.02;

    double start_time = 0;
    double T = 10;
    double nb_steps_per_year = 30;

    int NbSim = 1000;

    BSEULER1D* euler_process = new BSEULER1D(gen, S, r, vol);
    Milstein1D* milstein_process = new Milstein1D(gen, S, r, vol);

    //euler_process->Simulate(start_time, T, T * nb_steps_per_year);
    //milstein_process->Simulate(start_time, T, T * nb_steps_per_year);

    //for (int i = 0 ; i < T * nb_steps_per_year; ++i)
    //{
    //    std::cout << "FV = " << milstein_process->GetValue(i / nb_steps_per_year) << std::endl;
    //}

    EUCall call_euler(euler_process, S, K, r, vol, T);
    EUCall call_milstein(milstein_process, S, K, r, vol, T);

    std::cout << "Prix Euler: " << call_euler.ComputePrice(NbSim) << std::endl;
    std::cout << "Prix Milstein: " << call_milstein.ComputePrice(NbSim) << std::endl;

    std::cout << " Test 3 dimensions" << std::endl;

    std::vector<double> s3 = { 100.0, 50.0, 60.0 };
    std::vector<double> r3 = { 0.0, 0.0, 0.0 };
    Eigen::MatrixXd V{ {0.05,0.003,0.002},{0.003,0.07,0.001},{0.002,0.001,0.08} };

    BSEulerND* EulerND = new BSEulerND(gen, 3, s3, r3, V);
    EulerND->Simulate(0, 5, 5);

    std::cout << "Final Value : " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << i << ": " << EulerND->GetValue(5, i) << std::endl;
    }



    return 0;



}

