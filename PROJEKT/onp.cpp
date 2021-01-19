int expressionToRPN(string tab[], string ONP[]) {
    string stack[100];
    int stackCount = 0;
    int tabCount = 0;
    int ONPCount = 0;
    string element;
    
    while(true) {
        
        
        element = tab[tabCount++];
        if(element == "=") {
            while (stackCount > 0){
                ONP[ONPCount++] = stack[--stackCount];
            }
            break;
        }
        
        if(element.size() == 1) {
            switch(element[0]) {
                case '(': 
                    stack[stackCount++] = '(';
                    break;
                
                case ')': 
                    while(stack[stackCount - 1][0] != '(') {
                        ONP[ONPCount++] = stack[--stackCount];
                    }
                    stackCount--;
                    break;    
                
                case '+': ;                
                case '-': ;
                case '*': ;
                case '/': ;
                case '^': ;
                case 'q': ;
                case 'i': ;
                case 'o': ;
                case 'g': ;
                case 't': 
                    while(stackCount >= 0) {
                        if (stackCount != 0 && priority(stack[stackCount - 1][0]) >= priority(element[0])){
                            ONP[ONPCount++] = stack[--stackCount];
                        } else {
                            break;
                        }        
                    }
                    stack[stackCount++] = element;
                    break;
                default:
                    ONP[ONPCount++] = element;
                    break;    
            }
        } else {
            ONP[ONPCount++] = element;
        }
        
        
        
    }

    return ONPCount;    
}