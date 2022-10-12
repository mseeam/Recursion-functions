/*
  Author:         Mohammad Seeam
  Purpose:        Practice recursion by implementing looping functions as recursive functions
  
  IMPORTANT: Your recursive functions should NOT use any static local variables
  or global variables! The "state" of the function must be completely self-contained.
  A recursive functions may be called simultaneously by several programs at the same
  time. This occurs when a recursive function is in a library, such as qsort().
  If calls are not independent, the recursive function is limited to a single process.
  
  Use care that your recursive functions call THEMSELVES - not some OTHER function.
  
  Search on "modify" to find places to insert your code or modify existing code.
*/

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm> // for min, max
using namespace std;

void show_1_to_n_loop(int n) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=1; i<=n; ++i) cout<<i<<" ";
}

void show_1_to_n_recurse(int n) { // recursive
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here; modify...
  if (n<=0){
    return;
  }else{
    show_1_to_n_recurse(n-1);
    cout<< n << " ";
  }
}

void show_n_to_1_loop(int n) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=n; i>=1; --i) cout<<i<<" ";
}

void show_n_to_1_recurse(int n) { 
  // recursive
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here; modify...
  if (n<=0){
    return;
  }else{
    cout<< n << " ";
    show_n_to_1_recurse(n-1);
  }
}

string reverse_loop(string forward) { // looping, PROVIDED, DO NOT CHANGE
  string backwards;
  int size=forward.size();
  for (int i=0; i<size; ++i) {
    backwards+=forward[size-1-i];
  }
  return backwards;
}

string reverse_recurse(string forward) { // recursive
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here; modify..
  if (forward.length() == 1) {
    return forward;
  }else{
    string ret = reverse_recurse(forward.substr(1,forward.length())) + forward.at(0);
    return ret;
  }
}

//Palindrome check
// The function which shows palindrome
//Since I can not touch the main function 
// I just wrote the function
//did not call it from main function
bool palindrome_check(string str,int start,int end){
  if(start >= end) //base case
  return true;
  else{
    //if mismatch happens false will be returned else true
    return ((str[start] == str[end]) && palindrome_check(str,start+1,end-1));
  }
}

//the below code can be used in main function 
//to check my written plindrome function
/*
string str="madam";
int length=str.size();
  bool ans = palindrome_check(str, 0,length-1);
  if (ans == true){
    cout<<"YES, it is a Palindrome";}
  else{
    cout<<"NO, it is not a Palindrome";
  }
*/

int add2_fx(int a, int b) { // functional (for illustration only), PROVIDED, DO NOT CHANGE
  return a+b;
}

int add2_loop(int a, int b) { // looping, PROVIDED, DO NOT CHANGE
  int sum=a;
  if (b>0)
    for (int i=0; i<b; ++i) ++sum;
  else // b<=0
    for (int i=b; i<0; ++i) --sum;
  return sum;
}

int add2_recurse(int a, int b) { // recursive
  // Rule: Do NOT use the *, /, +, =, *=, /=, +=, -=, ^, &, <<, >> operators.
  // DO NOT USE bitwise operators like: (a & b) << 1; These are not part of the course.
  // You MAY use: ++ and/or -- (as done in add2_loop)
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here; modify...
  
  //base case
  if(b==0) return a;

  if(a>=0 && b> 0){
    return add2_recurse(++a, --b);
  }else if(a<0 && b > 0){
    return add2_recurse(++a, --b);
  }else if(a>=0 && b< 0){
    return add2_recurse(--a, ++b);
  }else if(a<0 && b < 0 ){
    return add2_recurse(--a, ++b);}  
    return 0; //dummy return 
};

int mult2_fx(int a, int b) { // functional (for illustration only), PROVIDED, DO NOT CHANGE
  return a*b;
}

int mult2_loop(int a, int b) { // looping, PROVIDED, DO NOT CHANGE
  int product=0;
  if (b>0)
    for (int i=0; i<b; ++i) product+=a;
  else // b<=0
    for (int i=b; i<0; ++i) product-=a;
  return product;
}

int mult2_recurse(int a, int b) {
  // recursive
  // Rule: you may NOT use the *, *=, / or /= operators.
  // You MAY use: +, -, +=, -= operators (as done in mult2_loop)
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here; modify...
  if (a == 0 || b == 0) {
        return 0;
  }else if( b < 0 ) {
    return -a + mult2_recurse(a, b + 1);
  }else {
    return a + mult2_recurse(a, b - 1);
  }
}

int search_loop(int array[], int size, int target) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=0; i<size; ++i)
    if (array[i]==target) {return i;}
  return -1;
}

int search_recurse(int array[], int size, int target) { // recursive
  // Constraints: No loops allowed; no static local or global variables.
  // Your new code goes here; modify...
  int rec;
    size--;
    if (size >= 0) {
        if (array[size] == target)
            return size;
        else
            rec = search_recurse(array, size, target);
    }
    else
        return -1;
    return rec;

  return 0; 
}

//extra credit function
//for diamond shape
//used both looping and recursion
void diamond_check(int a=10, int b=1, int c=10) { 
    for (int i = 1; i < a; i++) {
        printf(" ");
    }
    for (int i = 0; i < 2 * b - 1; i++) {
        printf("*");
    }
    printf("\n");
    if (b < c) {
        diamond_check(a - 1, b + 1, c);
        for (int i = 1; i < a; i++) {
            printf(" ");
        }
        for (int i = 0; i < 2 * b - 1; i++) {
            printf("*");
        }
        printf("\n");
    }
}

//the below function can be used in main function to check my diamond/extra credit function
// PrintPattern2(10,1,10);  
//I did not call it
//since I can't touch the main() function

enum control_flow_t {functional, looping, recursive};
void show_test(int n, string s, control_flow_t control_flow) {
  // utility function to format test output
  // n: test number; s: "description"; control_flow: functional, looping or recursive
  static const string fx="functional", sl="looping", sr="recursive";
  int max_len=max(fx.size(), max(sl.size(), sr.size()));
  string msg;
  switch (control_flow) {
    case functional: msg=fx;     break;
    case looping:    msg=sl;     break;
    case recursive:  msg=sr;     break;
    default:         msg="??";   break;
  }
  char iorr=msg[0];
  msg=" ("+msg+"): ";
  cout<<"\n"<<n<<iorr<<") "<<s<<setw(max_len+5)<<left<<msg;
}

void infinite_recursion() {
  // try at your own risk! Error message can be interesting.
  infinite_recursion();
}

// This code may be helpful when developing your recursive functions.
void recurse(int times_to_call) {
  // a generalized recursion outline; has 5 locations to do work...
  cout << "recurse head... " << "("<<times_to_call<<") " <<endl; // ALWAYS
  if (times_to_call>1) { // decision to recursive call
    cout << "recurse before call... " << "("<<times_to_call<<") " <<endl;
    recurse(times_to_call-1); // work (problem simplification) can be done inside the parameter list!
    cout << "recurse after call... " << "("<<times_to_call<<") " <<endl;
  } else {
    cout << "recurse else option... " << "("<<times_to_call<<") " <<endl;
  }
  cout << "recurse ...tail " << "("<<times_to_call<<") " <<endl; // ALWAYS
}

int main () {
  const string FIRSTNAME= "Mohammad"; // modify / change this to your first name
  const string LASTNAME= "Seeam";   // modify / change this to your last name
  
  // ----- DO NOT CHANGE ANY CODE BELOW in main(). CODE BELOW CALLS FUNCTIONS ABOVE FOR TESTING -----
  
  cout<<"start...\n";
  
  show_test(1, "show_1_to_n", looping);    show_1_to_n_loop(15);
  show_test(1, "show_1_to_n", looping);    show_1_to_n_loop(-9);    // handle unexpected values
  show_test(1, "show_1_to_n", recursive);  show_1_to_n_recurse(15);
  show_test(1, "show_1_to_n", recursive);  show_1_to_n_recurse(-9); // avoid runaway recursion
  cout<<endl;
  
  show_test(2, "show_n_to_1", looping);    show_n_to_1_loop(11);
  show_test(2, "show_n_to_1", looping);    show_n_to_1_loop(-5);    // handle unexpected values
  show_test(2, "show_n_to_1", recursive);  show_n_to_1_recurse(11);
  show_test(2, "show_n_to_1", recursive);  show_n_to_1_recurse(-5); // avoid runaway recursion
  cout<<endl;
  
  show_test(3, "reverse", looping);    cout<<reverse_loop("dad & mom & bob & sis live stressed");
  show_test(3, "reverse", looping);    cout<<reverse_loop(FIRSTNAME);
  show_test(3, "reverse", looping);    cout<<reverse_loop(LASTNAME);
  show_test(3, "reverse", recursive);  cout<<reverse_recurse("mom & dad & bob & sis live stressed");
  show_test(3, "reverse", recursive);  cout<<reverse_recurse(FIRSTNAME);
  show_test(3, "reverse", recursive);  cout<<reverse_recurse(LASTNAME);
  cout<<endl;

  show_test(4, "add2", functional);
  cout<<add2_fx( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_fx(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_fx(20, -9); cout<<" ";  // correct:  11
  cout<<add2_fx(-7, -5); cout<<" ";  // correct: -12
  show_test(4, "add2", looping);
  cout<<add2_loop( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_loop(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_loop(20, -9); cout<<" ";  // correct:  11
  cout<<add2_loop(-7, -5); cout<<" ";  // correct: -12
  show_test(4, "add2", recursive);
  cout<<add2_recurse( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_recurse(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_recurse(20, -9); cout<<" ";  // correct:  11
  cout<<add2_recurse(-7, -5); cout<<" ";  // correct: -12
  cout<<endl;

  show_test(5, "mult2", functional);
  cout<<mult2_fx( 50,   2); cout<<" ";  // correct:  100
  cout<<mult2_fx( 5,  -40); cout<<" ";  // correct: -200
  cout<<mult2_fx(-100,  3); cout<<" ";  // correct: -300
  cout<<mult2_fx(-4, -100); cout<<" ";  // correct:  400
  show_test(5, "mult2", looping);
  cout<<mult2_loop( 50,   2); cout<<" ";  // correct:  100
  cout<<mult2_loop( 5,  -40); cout<<" ";  // correct: -200
  cout<<mult2_loop(-100,  3); cout<<" ";  // correct: -300
  cout<<mult2_loop(-4, -100); cout<<" ";  // correct:  400
  show_test(5, "mult2", recursive);
  cout<<mult2_recurse( 50,   2); cout<<" ";  // correct:  100
  cout<<mult2_recurse( 5,  -40); cout<<" ";  // correct: -200
  cout<<mult2_recurse(-100,  3); cout<<" ";  // correct: -300
  cout<<mult2_recurse(-4, -100); cout<<" ";  // correct:  400
  cout<<endl;
  
  int primes[] = {211, 307, 401, 503, 601, 701, 809, 907, 1009, 1103}; // some numbers to search for
  int size_primes=sizeof(primes)/sizeof(primes[0]);  // get #elements in array
  
  show_test(6, "search", looping);
  cout<<search_loop(primes, size_primes, 211)<<", ";
  cout<<search_loop(primes, size_primes, 401)<<", ";
  cout<<search_loop(primes, size_primes, 907)<<", ";
  cout<<search_loop(primes, size_primes, 1103);
  show_test(6, "search", recursive);
  cout<<search_recurse(primes, size_primes, 211)<<", ";
  cout<<search_recurse(primes, size_primes, 401)<<", ";
  cout<<search_recurse(primes, size_primes, 907)<<", ";
  cout<<search_recurse(primes, size_primes, 1103)<<endl;
  
  // infinite_recursion();  // uncomment to experience infinite recursion (crash, error message)
  
  cout<<"\n...end\n";

  return 0;
} // end of main

// When complete, there will be test output for each of the 6 steps in pairs:
// looping and recursive. Your output should match.

/*
start...

1l) show_1_to_n (looping):    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
1l) show_1_to_n (looping):    
1r) show_1_to_n (recursive):  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
1r) show_1_to_n (recursive):  

2l) show_n_to_1 (looping):    11 10 9 8 7 6 5 4 3 2 1 
2l) show_n_to_1 (looping):    
2r) show_n_to_1 (recursive):  11 10 9 8 7 6 5 4 3 2 1 
2r) show_n_to_1 (recursive):  

3l) reverse (looping):    desserts evil sis & bob & mom & dad
3l) reverse (looping):    dammahoM
3l) reverse (looping):    maeeS
3r) reverse (recursive):  desserts evil sis & bob & dad & mom
3r) reverse (recursive):  dammahoM
3r) reverse (recursive):  maeeS

4f) add2 (functional): 9 10 11 -12 
4l) add2 (looping):    9 10 11 -12 
4r) add2 (recursive):  9 10 11 -12 

5f) mult2 (functional): 100 -200 -300 400 
5l) mult2 (looping):    100 -200 -300 400 
5r) mult2 (recursive):  100 -200 -300 400 

6l) search (looping):    0, 2, 7, 9
6r) search (recursive):  0, 2, 7, 9

...end
*/