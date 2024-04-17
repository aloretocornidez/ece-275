#ifndef ACKERMNANN_H
#define ACKERMNANN_H


// Define the ackermann function here to return an interger and accept two
// integer values
int ackermann(int x, int y){
    if(x == 0) return y+1;
    else if(y == 0) return ackermann(x-1, 1);
    else return ackermann(x-1, ackermann(x, y-1));
}

#endif
