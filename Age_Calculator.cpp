#include <iostream>
using namespace std;


   int cd,cm,cy;
   int bd,bm,by;
   
  void set_dob(int d, int m, int y)
  {
  	cd = d;
  	cm = m;
  	cy = y;
  /* cout<<"Set Today's date: DD/MM/YYYY: ";
    cin>>cd>>cm>>cy; 
    
    cout<<"Perfect \n Now set Your Date of Birth \n"; */
    
    cout<<"Set Date of Birth date: DD/MM/YYYY: ";
    cin>>bd>>bm>>by;
    
    if(cd < bd)
    {
        cd = cd + 30;
        cm = cm - 1;
        cd = cd - bd;
    } 
    else
    {
        cd = cd - bd;
    }
    
    if(cm < bm)
    {
        cm = cm + 12;
        cy = cy - 1;
        cm = cm - bm;
    } 
    else
    {
        cm = cm - bm;
    }
    
    cy = cy - by;
    
    }
  
  
  void get_dob()
  {
      
    cout<<"You are: \n"<<cy<<" Years \n"<<cm<<" Months \n"<<cd<<" Days old.";
  }



int main()
{
    set_dob(28,03,2024);
    get_dob();
    
return 0;
}