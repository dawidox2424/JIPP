double ONPToResult(string ONP[]) {
    
    double result[100];
    double a;
    double b;
    int ONPCount = 0;
    int resultCount = 0;
    string element;    
    const double PI = 3.14159265;
    while(true) {
        
        element = ONP[ONPCount++];
        
    
        if(element == "=") {
            return result[--resultCount];
            
        } else if(isNumber(element[0]) || (element[0] == '-' && element.size() > 1)) {
            
            result[resultCount++] = stod(element);

        } else {

            if ((element[0] > 41 && element[0] < 48) || element[0] == 94) {

                b = result[--resultCount];
                a = result[--resultCount];

                switch(element[0]) {
                    
                    case '+': a += b; break;
                    case '-': a -= b; break;    
                    case '*': a *= b; break;
                    case '/': a /= b; break;
                    case '^': a = pow(a, b); break;
                    default: break;
            
                }
            }     else {
                    a = result[--resultCount];
                    switch(element[0]) {

                    case 'i': a = sin(a*(PI/180)); break;
                    case 'o': a = cos(a*(PI/180)); break;
                    case 'g': a = tan(a*(PI/180)); break;
                    case 't': a = 1/tan(a*(PI/180)); break;
                    case 'q': a = sqrt(a); break;
                    default: break;
                    }
                }    
        //cout << a << endl;
        result[resultCount++] = a;
        }

    }
    
}