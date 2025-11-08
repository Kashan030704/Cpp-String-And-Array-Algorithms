#include <iostream>
#include <cmath>

//Author: Kashan Khan
//Grade Calculator

//Function declaration
int main(); 

//Function definition
int main() {
    double final_exam_grade{};
    float final_exam_max_grade{};
    double mid_exam_grade{};
    float mid_exam_max_grade{};
    double proj_1_grade{};
    float proj_1_max_grade{};
    double proj_2_grade{};
    float proj_2_max_grade{};
    double proj_3_grade{};
    float proj_3_max_grade{};
    double proj_4_grade{};
    float proj_4_max_grade{};
    double proj_5_grade{};
    float proj_5_max_grade{};


    //Prompting user for final exam maximum grade, and grade achieved.
    std::cout << "Enter your final exam maximum grade: ";
    std::cin>> final_exam_max_grade;
    while(final_exam_max_grade <= 0 || final_exam_max_grade != std::round(final_exam_max_grade)) {
        std::cout << "Please, Enter a valid final exam maximum grade: ";
        std::cin>> final_exam_max_grade;
    }

    std::cout << "Enter your final exam grade achieved: ";
    std::cin >> final_exam_grade;
    while(final_exam_grade < 0 || final_exam_grade > final_exam_max_grade) {
        std::cout << "Please, Enter a valid final exam grade achieved: ";
        std::cin>> final_exam_grade;
    }

    
    //Prompting user for mid-term exam maximum grade, and grade achieved.
    std::cout << "Enter your mid-term exam maximum grade: ";
    std::cin>> mid_exam_max_grade;
    while(mid_exam_max_grade <= 0 || mid_exam_max_grade != std::round(mid_exam_max_grade)) {
        std::cout << "Please, Enter a valid mid term maximum grade: ";
        std::cin>> mid_exam_max_grade;
    }

    std::cout << "Enter your mid-term exam grade achieved: ";
    std::cin>> mid_exam_grade;
    while(mid_exam_grade < 0 || mid_exam_grade > mid_exam_max_grade) {
        std::cout << "Please, Enter a valid mid-term grade achieved: ";
        std::cin>> mid_exam_grade;
    }

    //Prompting user for project 1 maximum grade, and grade achieved.
    std::cout << "Enter your Project 1 maximum grade: ";
    std::cin>> proj_1_max_grade;
    while(proj_1_max_grade <= 0 || proj_1_max_grade != std::round(proj_1_max_grade)) {
        std::cout << "Please, Enter a valid Project 1 maximum grade: ";
        std::cin>> proj_1_max_grade;
    }

    std::cout << "Enter your Project 1 grade achieved: ";
    std::cin>> proj_1_grade;
    while(proj_1_grade < 0 || proj_1_grade > proj_1_max_grade) {
        std::cout << "Please, Enter a valid Project 1 grade achieved: ";
        std::cin>> proj_1_grade;
    }

    //Prompting user for project 2 maximum grade, and grade achieved
    std::cout << "Enter your Project 2 maximum grade: ";
    std::cin>> proj_2_max_grade;
    while(proj_2_max_grade <= 0 || proj_2_max_grade != std::round(proj_2_max_grade)) {
        std::cout << "Please, Enter a valid Project 2 maximum grade: ";
        std::cin>> proj_2_max_grade;
    }

    std::cout << "Enter your Project 2 grade achieved: ";
    std::cin>> proj_2_grade;
    while(proj_2_grade < 0 || proj_2_grade > proj_2_max_grade ) {
        std::cout << "Please, Enter a valid Project 2 grade achieved: ";
        std::cin>> proj_2_grade;
    }

    //Prompting user for project 3 maximum grade, and grade achieved
    std::cout << "Enter your Project 3 maximum grade: ";
    std::cin>> proj_3_max_grade;
    while(proj_3_max_grade <= 0 || proj_3_max_grade != std::round(proj_3_max_grade)) {
        std::cout << "Please, Enter a valid Project 3 maximum grade: ";
        std::cin>> proj_3_max_grade;
    }

    std::cout << "Enter your Project 3 grade achieved: ";
    std::cin>> proj_3_grade;
    while(proj_3_grade < 0 || proj_3_grade > proj_3_max_grade ) {
        std::cout << "Please, Enter a valid Project 3 grade achieved: ";
        std::cin>> proj_3_grade;
    }

    //Prompting user for project 4 maximum grade, and grade achieved
    std::cout << "Enter your Project 4 maximum grade: ";
    std::cin>> proj_4_max_grade;
    while(proj_4_max_grade <= 0 || proj_4_max_grade != std::round(proj_4_max_grade)) {
        std::cout << "Please, Enter a valid Project 4 maximum grade: ";
        std::cin>> proj_4_max_grade;
    }

    std::cout << "Enter your Project 4 grade achieved: ";
    std::cin>> proj_4_grade;
    while(proj_4_grade < 0|| proj_4_grade > proj_4_max_grade) {
        std::cout << "Please, Enter a valid Project 4 grade achieved: ";
        std::cin>> proj_4_grade;
    }

    //Prompting user for project 5 maximum grade, and grade achieved
    std::cout << "Enter your Project 5 maximum grade: ";
    std::cin>> proj_5_max_grade;
    while(proj_5_max_grade <= 0 || proj_5_max_grade != std::round(proj_5_max_grade)) {
        std::cout << "Please, Enter a valid Project 5 maximum grade: ";
        std::cin>> proj_5_max_grade;
    }

    std::cout << "Enter your Project 5 grade achieved: ";
    std::cin>> proj_5_grade;
    while(proj_5_grade < 0 || proj_5_grade > proj_5_max_grade) {
        std::cout << "Please, Enter a valid Project 5 grade achieved: ";
        std::cin>> proj_5_grade;
    }

    
    //Curve essentially, and replaces the projects/assignments that are less than f_100
    double f_100{(final_exam_grade/final_exam_max_grade)*100};

    double m_100{(mid_exam_grade/mid_exam_max_grade)*100};

    double p_1{(proj_1_grade/proj_1_max_grade)*100};

    double p_2{(proj_2_grade/proj_2_max_grade)*100};

    double p_3{(proj_3_grade/proj_3_max_grade)*100};

    double p_4{(proj_4_grade/proj_4_max_grade)*100};

    double p_5{(proj_5_grade/proj_5_max_grade)*100};

    double temp_{f_100};
    //testing for values (troubleshooting)
    //std::cout<< "test for f_100: " << f_100 << std::endl;
    //std::cout << "test for m_100: " << m_100 << std::endl;

    if (f_100 > m_100) {
        m_100 = temp_;
    }

    if (f_100 > p_1) {
        p_1 = temp_;
    }

    if (f_100 > p_2) {
        p_2 = temp_;
    }

    if(f_100 > p_3) {
        p_3 = temp_;
    }

    if(f_100 > p_4) {
        p_4 = temp_;
    }
    
    if (f_100 > p_5) {
        p_5 = temp_;
    }

    //Examination Weighted Average
    double e_100{0.75*f_100 + 0.25*m_100};
    //troubleshooting -- issue with this calculation
    //std::cout<< "test for Exam weighted avrg: " << e_100 << std::endl;

    //Project Grade
    double p_100{((p_1 + p_2 + p_3 + p_4 + p_5)*0.2)};

    //troubleshooting
    //std::cout<< "test for project grade: " << p_100 << std::endl;

    //Final Grade
    if (e_100 <= 40) {
        std::cout << "Final grade: " << std::round(e_100) << std::endl;
    } else if( 40 < e_100 && e_100 < 60) {
        double f_g{((e_100*e_100)/(-60))+(5.0/3.0)*e_100 + ((p_100)*(e_100))/(60) + (-2.0/3.0)*p_100};
        std::cout << "Final grade: " << std::round(f_g + 1e-12) << std::endl;
    } else if (e_100 >= 60) {
        double fg{(1.0/2.0)*f_100 + (1.0/6.0)*m_100 + (p_100/3)};
        std::cout << "Final grade: " << std::round(fg + 1e-12) << std::endl;
    }



return 0;


}

