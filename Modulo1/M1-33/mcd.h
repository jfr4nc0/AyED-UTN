//
// Created by neur0tik on 9/11/21.
//

#ifndef M1_33_MCD_H
#define M1_33_MCD_H

void mcd(int A,int B, int &MCD)
{
    int R=A/B;
    while ( R>=0 && B>=R)
    {
        if( R==0 ){
            MCD=B;
        }
        A=B;
        B=R;
        R=A/B;
    }
    return;
}

#endif //M1_33_MCD_H
