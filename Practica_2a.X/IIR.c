


float IIR_p(int* coeffs, int input) 
{
    X_a[0] = (*Gaina) * input;
    
    w_a[0] = ((*Dena0) * X_a[0]) - ((*Dena1) * X_a[1]) - ((*Dena2) * X_a[2]);
    Y_a = ((*Numa0) * W_a[0]) + ((*Numa1) * W_a[1]) + ((*Numa2) * W_a[2]);
    W_a[2] = W_a[1];
    W_a[1] = W_a[0];
    
    
//    X_b[0] = (*Gainb) * Y_a;
//    
//    w_b[0] = ((*Denb0) * X_b[0]) - ((*Denb1) * X_b[1]) - ((*Denb2) * X_b[2]);
//    Y_b = ((*Numb0) * W_b[0]) + ((*Numb1) * W_b[1]) + ((*Numb2) * W_b[2]);
//    W_b[2] = W_b[1];
//    W_b[1] = W_b[0];
    
    return 
}
