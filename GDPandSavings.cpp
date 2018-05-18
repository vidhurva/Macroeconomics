#include <iostream>
#include <string> 

using namespace std;

struct GDP {
  int inv ,con ,gov ,exp , gdp ,tax ,priv,pub, nat;
  string curr;
};

void GDP_calculator(GDP &r);
void private_savings(GDP &r);
void public_savings(GDP &r);
void national_savings(GDP &r);
void gov_status(GDP &r);
void print_data(GDP &r);

int main() {
  GDP r;
  
  cout << "Enter the amount of investment:";
  cin  >> r.inv;

  cout << "Enter the amount of consumption:";
  cin  >> r.con;

  cout << "Enter the amount of government spending:";
  cin  >> r.gov;

  cout << "Enter the amount earned from exports:";
  cin  >> r.exp;

  cout << "Enter the annual tax:";
  cin  >> r.tax;

  cout << "Enter the currency (Ex: USD, Euros) : ";
  cin  >> r.curr;

  print_data(r);
}

// Calculates total GDP. Note that imports are not accounted for. 
void GDP_calculator(GDP & r) 
{
  r.gdp = r.inv + r.con + r.gov + r.exp;
  cout << r.gdp;
}

void private_savings(GDP &r)
{
  r.priv = r.gdp - r.con - r.tax;
  cout << r.priv;
}

void public_savings(GDP &r)
{
  r.pub = r.tax - r.gov;
  cout << r.pub;
}

void national_savings(GDP &r)
{
  r.nat = r.gdp - r.con - r.gov ;
  cout << r.nat;
}

void gov_status(GDP &r)
{
  if(r.pub == 0)
    cout << "The government is experiencing a balanced budget";
  else if (r.pub >= 0)
    cout << "The government is experiencing a budget surplus";
  else
    cout << "The government is experiencing a budget deficit";

  cout << endl;   
}

void print_data(GDP &r)
{
  cout << endl;
  cout << "The GDP is: ";
  GDP_calculator(r);
  cout << " " << r.curr << endl;

  cout << "The Private Savings are: ";
  private_savings(r);
  cout << " " << r.curr << endl;

  cout << "The Public Savings are: ";
  public_savings(r);
  cout << " " << r.curr << endl;

  cout << "The National Savings are: ";
  national_savings(r);
  cout << " " << r.curr << endl;

  gov_status(r);
}