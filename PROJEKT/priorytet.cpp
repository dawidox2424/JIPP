int priority ( char c ) {
  switch ( c )
  {
    case '+': ;
    case '-': 
        return 1;
    case '*': ;
    case '/': 
        return 2;
    case '^': 
        return 3;
    case 'q': ;
    case 'i': ;
    case 'o': ;
    case 't': ;    
    case 'g': 
        return 4;    
  }
  return 0;
}