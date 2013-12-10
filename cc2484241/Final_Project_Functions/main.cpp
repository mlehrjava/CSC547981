/*
  Christian Conable
  12/10/2013
  Final Project 
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void last_year_gpa(float a[], float ave);  

int main(int argc, char *argv[]){
    const int last_years = 3;
    const int this_year = 4;
    const int col = 3;  
    
    float gpa[last_years], average;
    ifstream in_stream; 
    in_stream.open("intro.txt");
    if ( in_stream.fail() == false )
       cout << "\n";
    else if ( in_stream.fail() == true ){
       cout << "The program will now proceed to close\n";
       exit(1);
    }
    string line_of_text; 
    
    
    do {
        getline (in_stream, line_of_text); 
        cout << line_of_text << endl; 
    }while(!in_stream.eof());
    
    
    
    in_stream.close();
    
    cout << endl << "\nThere are certain boundaries that you should take into consideration " << endl; 
    cout << "before continuing with the program:" << endl; 
    cout << endl << setw(64) << "1. The Computer Science PhD program only considers" << endl; 
    cout << setw(65) << "applicants with a GPA over a 3.0. Anything below" << endl; 
    cout << setw(70) << "this minimum requirement will be thrown in the trash." << endl; 
    cout << endl << setw(62) << "2. The GRE scoring standards are measured based " << endl; 
    cout << setw(65) << "from a 260 - 340 scale. Anything above or below " << endl; 
    cout << setw(65) << "this range will dismiss the potential applicant." << endl; 
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
     
     char choice; 
     do {
            //Input the respective GPA's for last year's students
            cout << endl << endl << "Input the cumulative grade \n"
                 << "point average for the five\n"
                 << "Computer Science PhD students in last\n"         
                 << "year's entering class. Please enter each\n" 
                 << "GPA in decimal format (ex. 3.45)." << endl; 
            
            last_year_gpa(gpa, average);
            cout << endl << endl << "This next section will take the average GRE score for last year's\n"
             << "entering class. Note that the Computer Science Department requires each\n"
             << "student to take the GRE three times and takes the average\n"               //Store this in input file
             << "of each student's scores. The average for the entire class is calculated\n"
             << "from the averages of each student." << endl; 
                 
       //Input the respective GRE scores for each student (3 GRE scores per student).
       int score[last_years][col], sum = 0, st_ave[last_years]; 
       for (int i = 0; i <= last_years - 1; i++){
           for(int j = 0; j < col; j++){
              cout << endl << "On the " << j + 1 << " attempt of taking\n"
                   << "the GRE, student " << i + 1 << " scored: "; 
              cin >> score[i][j];
              if (score[i][j] <= 260){
                 cout << endl << "there is no score lower than 260 on the \n"
                      << "most current GRE exams, therefore this\n"
                      << "is an invalid entry." << endl; 
              }
              else if (score[i][j] > 340){
                 cout << endl << "A perfect score is 340, therefore this is\n"
                      << "an invalid entry." << endl;
              }
              else
                 sum += score[i][j]; 
           }
          
           st_ave[i] = sum/col; 
           if (st_ave[i] < 260 || st_ave[i] > 340)
              cout << "This averaged GRE score is not within the range of 260 - 340." << endl; 
           else {
              sum = 0;                                  
              cout << endl << endl << setw(45) << "Student " << i + 1 << " had an average " << endl; 
              cout << setw(53) << "GRE score of " << st_ave[i] << "." << endl;
           } 
       } 
       //Calculate addition of the GRE scores.
       int total1 = 0; 
       for (int i = 0; i < last_years; i++){
            for (int j = 0; j < col; j++)  
                total1 += score[i][j];
        }
        //Calculate the average GRE score based on the averages from each student (The average for the whole class). 
        int average1; 
        average1 = total1/(last_years*col); 
        if (average1 <= 260){
           cout << endl << "The overall GRE score is below the " << endl; 
           cout << "lowest possible score of 260." << endl; 
           break;  
        }
        else if (average1 > 340){
           cout << endl << "This average GRE score exceeds the " << endl; 
           cout << "highest possible score of 340." << endl; 
           break; 
        }
        else{
           cout << endl << endl << "The average GRE score for " << endl; 
           cout << "last year's class was " << average1 << "." << endl;
        }
        
       //Compute the product of the average GRE and average GPA from last year's class.
       float product; 
       product = average1*average;
       cout << "GRE Average = " << average1 << "\n"; 
       cout << endl << "GPA Average = " << average << "\n"; 
       cout << endl << "Product = " << product << "\n" << endl; 
       
       cout << "Student" << setw(22) << "GRE Scores" << endl; 
       for (int i = 0; i < last_years; i++){
           cout << i + 1 << " "; 
            for (int j = 0; j < col; j++)
                cout << setw(10) << score[i][j]; 
           cout << endl << endl; 
           }
       cout << "Ave = "; 
       for (int i = 0; i <= last_years - 1; i++)
           cout << setw(8) << st_ave[i]; 
       
       //Input the GPA for the six current students.
       cout << endl << endl << "This next part of the program will give the likelihood of six\n"
            << "applicants getting into the PhD program based on their grade\n"
            << "point averages and GRE scores. The computer will compare each\n"
            << "student's credentials with last year's credentials." << endl; 
            
       float this_year_gpa[this_year], total3 = 0.0e0f; 
       for (int count2 = 0; count2 < this_year - 1; count2++){
           cout << endl << "Input the GPA for student " << count2 + 1 << ": "; 
           cin >> this_year_gpa[count2];
           if (this_year_gpa[count2] < 0.01e0f){
              cout << "The grade point average must be" << endl; 
              cout << "above a 0.01, therfore this is an " << endl; 
              cout << "invalid entry." << endl; 
           }
           else if (this_year_gpa[count2] < 3.0e0f){
              cout << "The Computer Science Department only " << endl; 
              cout << "accepts applicants with a grade point average" << endl; 
              cout << "above a 3.00." << endl;
           }
           else if (this_year_gpa[count2] > 4.0e0f){
              cout << "The grade point average must be below" << endl; 
              cout << "a 4.0, therefore this is an invalid entry." << endl;
           }
           else 
              total3 += this_year_gpa[count2]; 
       }
       //Input the three GRE scores of the six prospective students (this year).
       float this_year_prod[this_year], percentage[this_year];
       cout << endl << "Now we will determine the average GRE score for the five current" << endl; 
       cout << "applicants. Remember to stay in the range of 260 - 340." << endl; 
       int score1[this_year][col], st_ave2[this_year], sum2 = 0; 
       for (int k = 0; k < this_year - 1; k++){
           for (int l = 0; l < col; l++){
               cout << endl << "What was the GRE score\n"
                    << "for the " << k + 1 << " student's " << l + 1 << "\n"
                    << "GRE score?" << endl; 
               cin >> score1[k][l]; 
               if (score1[k][l] <= 260){
                   cout << endl << "there is no score lower than 260 on the \n"
                        << "most current GRE exams, therefore this\n"
                        << "is an invalid entry." << endl; 
               }
               else if (score1[k][l] > 340){
                   cout << endl << "A perfect score is 340, therefore this is\n"
                        << "an invalid entry." << endl;
               }
               else
                   sum2 += score1[k][l]; 
           }
           st_ave2[k] = sum2/col; 
           this_year_prod[k] = st_ave2[k]*this_year_gpa[k];
           cout << endl << "Average GRE score for student " << k + 1 << endl; 
           cout << " = " << setw(14) << st_ave2[k] << endl; 
           sum2 = 0; 
           cout << "Product = " << this_year_prod[k] << "\n" << endl;    
           percentage[k] = (this_year_prod[k]/product) * 100; 
           if (percentage[k] > 1.00e2f){
              cout << endl << "Student " << k + 1 << " will be accepted into the" << endl; 
              cout << "Fall 2014 Computer Science PhD program.";
              }
           else if (percentage[k] < 5.01e1f){
              cout << endl << endl << "Based on your current credentials, you're likelihood of being" << endl; 
              cout << "accepted into the program is less than 50%. Therefore, " << endl; 
              cout << "student " << k + 1 << "'s application will not be considered." << endl; 
           }
           else {
               cout << endl << "Consideration standard = (" << this_year_prod[k] << "/" << product << " )*100% = " << percentage[k] << endl; 
               cout << "Student " << k + 1 << " has a " << percentage[k] << "%" << endl; 
               cout << "chance of getting into the PhD program." << endl; 
           }
       }
       cout << endl << "Would you like to compare with a different class? " << endl; 
       cout << "Enter Y or N.: "; 
       cin >> choice; 
   }while (choice == 'Y' || choice == 'y'); 
    system("PAUSE");
    return EXIT_SUCCESS;
}
void last_year_gpa(float a[], float ave){
    float addition = 0;
    int last_years = 3;
    for (int i = 0; i <= last_years - 1; i++){
                    cout << endl << "Student " << i + 1 << "'s GPA\n"
                         << "was: "; 
                    cin >> a[i];
                    if (a[i] < 0.01e0f){
                       cout << endl << "The grade point average must be" << endl; 
                       cout << "above a 0.01, therfore this is an " << endl; 
                       cout << "invalid entry." << endl;  
                    }
                    else if (a[i] < 3.0e0f){
                       cout << endl << "The Computer Science Department only " << endl; 
                       cout << "accepts applicants with a grade point average" << endl; 
                       cout << "above a 3.00." << endl;
                    }
                    else if (a[i] > 4.0e0f){
                       cout <<  endl << "The grade point average must be below" << endl; 
                       cout << "a 4.0, therefore this is an invalid entry." << endl;
                    } 
                    else  
                       addition += a[i]; 
                }  
                ave = addition/last_years; 
                if (ave < 3.0e0f){
                    cout << "The average GPA for last year's class does not meet the " << endl; 
                    cout << "minimum GPA requirement for the class" << endl; 
                    cout << "And therefore does not exist." << endl;
                }
                else if (ave > 4.0e0f){
                    cout << "The average GPA for last year's class is over " << endl; 
                    cout << "the highest grade point average of a 4.0" << endl; 
                    cout << "and therefore does not exist." << endl;  
                }
                else{
                    cout << endl << "The average grade point average for the " << last_years << "\n"
                         << "students who were accepted into last year's\n"
                         << "Computer Science PhD program was a " << endl;
                    cout << endl << ave << " GPA.\n"; 
            }
}

