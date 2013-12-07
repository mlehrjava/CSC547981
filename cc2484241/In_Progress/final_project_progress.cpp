/*
  Christian Conable
  12/10/2013
  Final Project 
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int last_years = 6;
const int this_year = 6;
const int col = 3; 

int main(int argc, char *argv[]){ 
    cout << endl << "In this program, you are an admissions counselor at a public research \n"
         << "university and you're determining whether four undergraduate students\n"
         << "have a chance of getting into the college's prestigious\n" 
         << "Computer Science PhD program. You will make this decision\n"
         << "for each prospective student based on the academic statistics\n"
         << "from last year's entering class." << endl << endl; //You obviously should finish off this dialogue
        
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); 
     
    //Input the respective GPA for last year's students
    cout << endl << endl << "Input the cumulative grade \n"
         << "point average for the six\n"
         << "Computer Science PhD students in last\n"
         << "year's entering class." << endl; 
         
    int gpa[last_years]; 
    float addition = 0.0e0f;
        for (int i = 0; i <= last_years; i++){
            cout << endl << "Student " << i + 1 << "'s GPA\n"
                 << "was: "; 
            cin >> gpa[i];
            if (gpa[i] <= 0.0e0f || gpa[i] > 4.01e0f){
               cout << endl << "This grade point average is not between \n"
                    << "0.01 and 4.0, therefore this is\n"
                    << "an invalid entry." << endl; 
            }
            addition += gpa[i]; 
        }   
    //Compute the average GPA for that class.
    int i; 
    float average; 
    average = addition/gpa[i]; 
    cout << endl << "The average GPA for the " << last_years << "\n"
         << "students who were accepted into last year's\n"
         << "Computer Science PhD program was " << average << ".\n"; 
         
   //Input the respective GRE scores for each student (3 GRE scores per student).
   int score[last_years][col], sum = 0, st_ave[last_years]; 
   for (int i = 0; i <= last_years; i++){
       for(int j = 0; j < col; j++){
          cout << endl << "On the " << j + 1 << " attempt of taking\n"
               << "the GRE, student " << i + 1 << " scored: "; 
          cin >> score[i][j];
          if (score[i][j] <= 130){
             cout << endl << "there is no score lower than 130 on the \n"
                  << "most current GRE exams, therefore this\n"
                  << "is an invalid entry." << endl; 
          }
          else if (score[i][j] > 171){
             cout << "A perfect score is 170, therefore this is\n"
                  << "an invalid entry." << endl;
          } 
          else
             sum += score[i][j]; 
       }
       st_ave[i] = sum/col; 
       cout << endl; 
   } 
   //Calculate the average GRE Score per student. 
   for (int i = 0; i <= last_years; i++){
       cout << "The average GRE score for student\n"
            << i + 1 << " from last year's\n"
            << "entering class was " << st_ave[i] << "." << endl; 
   }
   
   //Calculate addition of all the GRE scores.
   int total1 = 0; 
   for (int i = 0; i < last_years; i++){
        for (int j = 0; j < col; j++)  
            total1 += score[i][j];
    }
    
    //Calculate the average GRE score based on the averages from each student (The average for the whole class). 
    int average1; 
    average1 = total1/(last_years*col); 
    cout << "The average GRE score for last year's class was " << average1 << "." << endl;

   //Compute the product of the average GRE and average GPA from last year's class.
   float product; 
   product = average1*average;
   
   //Input the GPA for the six current students.
   int count2 = 0;
   float this_year_gpa; 
   while (count2 < this_year){
       cout << "Input the GPA for student " << count2 + 1 << ": "; 
       cin >> this_year_gpa;
        if (this_year_gpa <= 0.0e0f){
           cout << endl << "That grade point average is below\n"
                << "0.01 and therefore is an invalid entry." << endl; 
        }
        else if (this_year_gpa > 4.01e0f){
           cout << endl << "That grade point average is above a \n"
                << "4.00 and therfore is an invalid entry." << endl; 
        } 
        else
          count2++;
   }
   
   //Input the three GRE scores of the six prospective students (this year).
   int score1[this_year][col], st_ave2[this_year], sum2 = 0; 
   for (int k = 0; k < this_year; k++){
       for (int l = 0; l < col; l++){
           cout << endl << "What was the " << k + 1 << " GRE score\n"
                << "for the " << l + 1 << " prospective student?";
           cin >> score1[k][l]; 
           sum2 += score1[k][l]; 
       }
       st_ave2[k] = sum2/this_year; 
   }
   //Compute the Average GRE from the three scores, for each of the six students.
   for (int k = 0; k < this_year; k++){
       cout << endl << "The average GRE score for the\n"
            << k + 1 << " student is " << st_ave2[k] << "." << endl; 
   }
   
   //Repeat the same process from step 7 of finding the product of the GPA and average GRE score for each student.
   
   //Compare each student's score from step 9 to step 7 
   //and give a percentage of their likelihood of getting into the PhD program.
   
   //If a prospective student's aggregate score is over last year's aggregate score (aka >= 612.89), 
   //the student is admitted into the program. Else, the percentage of likelihood (step 10) is executed. 
   
   
   
         
    system("PAUSE");
    return EXIT_SUCCESS;
}
