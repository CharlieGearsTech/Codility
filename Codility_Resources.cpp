#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

/*
 Para tener listo:

 1.Conexion a internet bien
 2.Hojas y lapicera, borrador completo
 3.Cargador bien
 4.Cpp Reference
 5.Qt creator bien
 6.Carpeta de ejercicios bien
 7.Resource bien.
 8.Github bien.
 9. Cracking the code
 
 Procedimiento
 0. Quitar el codility de firefox y hacerlo en chrome.
 1. Leer atentamente el problema. 
 1.1 PRESTA ATENCION A "HINTS" de CODILITY. Leason Learned: En un ejemplo, Codility daba un "hint" de que tambien tenia que realizar un chequeo de N a 0 y no solamente de 0 a N, por omitir esto, obtuve un 18% donde el algoritmo "adaptado" para checar N a 0 pudiera haber sacado el 100%. 
 2. Realizar ejemplos
 3. Encontrar un metodo brute force que garantice una calificacion minima.
 4. Haz pruebas con el brute force
 5. Si pasa los basicos, ponerlo en Codility
 6. Hacer pruebas de los limites y casos especiales que pueda haber
 7. Optimizar o buscar una solucion mas rapida.
 8. Dar una ultima revisada al texto.
 9. Mandarlo ya que va haber mas pruebas.

 */

using namespace std;

/*Retorna un arreglo donde los numeros primos estan identificados con 1 mientras que los compuestos estan en 0*/
vector<int> sieve(int n)
{
    vector<int> sieve(n+1,1);

    /* Para 0 y 1 que no son usados en la logica de sieve*/
    sieve[0] = 0;
    sieve[1] = 0;

    /* Empezamos con 2 como el numero mas pequeño*/
    auto i =2u;

    /* Limitando el rango a numeros que dividen a N*/
    while(i*i <= (size_t)n)
    {
        /* Revisar si hemos pasado por este valor*/
        if(false != sieve[i])
        {
            auto k=i*i;
            /* Loop del numero en analisis*/
            while(k <= (unsigned)n)
            {
                /* Marcar como numero compuesto*/
                sieve[k] = 0;
                /*Incrementar multiplos del posible numero primo para encontrar numeros compuestos*/
                k+=i;
            }
        }
        /*Move to search the next prime number*/
        i++;
    }
    return sieve;
}

/*Retorna un arreglo de numero primo*/
 vector<int> primeArray(const int N)
 {
     vector<int> sieve_=sieve(N);
     vector<int> prime;
     prime.reserve(N);

     for(auto idx=0; idx < N; ++idx)
         if(sieve_[idx] == 1)
             prime.push_back(idx);

     return prime;
 }

 /*Retorna un set ordenado de numero semiprimos que se definen por ser dividido por 2 numeros primos no repetidos*/
 set<int> semiPrimeArray(const int N, const vector<int>& primes)
 {
     set<int> semiPrime;

     for(auto i=0u;i<primes.size();++i)
    {
         for(auto j=0u; j<primes.size();++j)
         {
             if(primes[i]*primes[j] >N)
                 break;
             else
                semiPrime.insert(primes[i]*primes[j]);
         }
    }
     return semiPrime;
 }

/*Crea un arreglo en la que los indices muestran el numero divisible de la secuencia y el valor es el numero  divisor mas pequeño que lo divide*/
vector<int> prepareArrayFactor(int n)
{
    vector<int> f(n+1,0);

    auto i = 2u;

    /*Rango para numeros que pueden dividir a N*/
    while(i+i <=(size_t)n)
    {
        /*Si no ha sido analizado o es un numero divisible por otro divisor anterior*/
        if(f[i] == 0)
        {
            auto k=i*i;
            while((unsigned)k <= n)
            {
                /*Primera vez, setea el divisor como valor, esto ya no sera reemplazado por otros divisores*/
                if(f[k] == 0)
                    f[k] = i;
                k+=i;
            }
        }
        i++;
    }
    return f;
}

/* Encontrar los numeros primos (pueden ser duplicados) que multiplicados nos dan a X, X debe de ser un numero menor al tamaño de A*/
vector<int> factorization(int x, vector<int>& A)
{
    vector<int> primeFactors;

    /*Revisar unicamente numeros que son divisibles*/
    while(A[x] > 0)
    {
        /*Agregar el divisor a la lista de factorizacion*/
        primeFactors.push_back(A[x]);
        /* Dividir para disminuir el numero divisible en un factor menor.*/
        x /= A[x];
    }
    /*Agregar el ultimo numero divisor.*/
    primeFactors.push_back(x);

    return primeFactors;
}

/*Fibonacci rapido  O(1)*/
vector<int> f;
int fib(int n)
{
    f.reserve(n);
    /*Fibonacci no required for initial */
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    /*Si tenemos un calculo de fibinacci en una ejecucion anterior, podemos retornar en O(1)*/
    if (f[n])
        return f[n];

    int k = (n & 1)? (n+1)/2 : n/2;

    /*Esta formula disminuye por la mitad la recursion de fibonacci*/
    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
           : (2*fib(k-1) + fib(k))*fib(k);

    return f[n];
}

/*Fibonacci con O(n2)*/
int fibonacci(size_t n)
{
    if(n <= 1)
        return n;
    return fibonacci(n-1)+ fibonacci(n-2);
}

/*Fibonacci con O(n),llenado de un arreglo y retornando el indice que nos interesa*/
int dyn_fibonacci(size_t n)
{
    vector<int> fib(n+2);
    size_t i;

    fib[0]=0;
    fib[1]=1;

    /*Rellenar vector local con el fibonacci*/
    for(i=2 ; i<n; ++i)
        fib[i]=fib[i-1]+fib[i-2];
    /*Retornar el fibonacci del indice requerido.*/
    return fib[n];
}

/*Retorna el numero de triangulos  donde los palos (indexados por x,y,z) cumplan con: ax+ ay < az y x<y<z */
int numTriangle(vector<int>& A)
{
    size_t result = 0u;

    if(A.size()==1)
        return 1;

    /* Por cada x*/
    for(auto x = 0u; x < A.size(); ++x)
    {
        /*Z seteado 2 elementos despues de x*/
        auto z = x + 2;
        /*Por cada Y situado un elemento mas que x*/
        for( auto y = x+1; y < A.size(); ++y)
        {
            /*Checar la regla hasta que z sea un indice adentro del contenedor*/
            while(z<A.size() && A[x]+A[y] > A[z])
                z++;
            /* Retornar el ultimo rango z-x triangulos*/
            result+= z-y-1;
        }
    }
    return result;
}

/*Determina si la suma de los elementos de una sequencia continua en un arreglo es igual a S */
bool isSubsequenceEqualToS(vector<int>& A, int S)
{
    size_t front_idx = 0, total = 0;

    /* Incrementa el indice cuando la secuencia es mayor que S*/
    for(auto back_idx = 0u; back_idx < A.size();++back_idx)
    {
        /* Incrementa el indice mientras la secuencia sea menor o igual a S*/
        while(front_idx < A.size() && total+A[front_idx] <= S)
        {
            total += A[front_idx];
            front_idx++;
        }
        if(total == (size_t)S)
            return true;
        total -= A[back_idx];
    }
    return false;
}

/*Retorna el maximo comun divisor de 2 numeros*/
size_t gcd_sub(size_t a, size_t b)
{
    if(a==b)
        return a;
    if( a> b)
        return gcd_sub(a-b,b);
    else
        return gcd_sub(a,b-a);
}

/* Maximo comun divisor, maximo numero que puede dividir ambos numeros a y b, por ejemplo
    24 y 18 gcd es 2*/
size_t gcd(size_t a, size_t b)
{
    if( a%b == 0)
        return b;
    else
        return gcd(b, a%b);
}

size_t gcd_euclidean(size_t a,size_t b,size_t res)
{
    if( a == b)
        return res*a;
    else if(a%2 == 0 && b%2 == 0)
        return gcd_euclidean(floor(a/2),floor(b/2),2*res);
    else if(a%2 == 0)
        return gcd_euclidean(floor(a/2),b,res);
    else if(b%2 == 0)
        return gcd_euclidean(a, floor(b/2),res);
    else if (a>b)
        return gcd_euclidean(a-b,b,res);
    else
        return gcd_euclidean(a,b-a,res);
}

/* Minimo comun multiplo es el minimo numero que puede ser divisible por a y b por ejemplo
   para 4 y 3 el mcm es 12*/
size_t lcm_2(size_t a, size_t b)
{
    size_t lcm = 1;
    while(1)
    {
        if(lcm%a == 0&& lcm%b == 0)
            return lcm;
        lcm++;
    }
}

size_t lcm_vector(vector<int>& A)
{
    size_t lcm = lcm_2(A[0],A[1]);

    for(auto i = 2u; i< A.size();++i)
        lcm = lcm_2(lcm,A[i]);

    return lcm;
}

/* Return the number of divisor that one number might have:
    10 has 4 -> 5, 10, 1, 2*/
int numberOfDivisors(size_t n)
{
    auto i = 1u;
    auto result=0u;

    while(i*i < n)
    {
        if(n%i == 0u)
            result +=2;
        i++;
    }
    if(i*i == n)
        result ++;

    return result;
}


/* Returns true when the number is prime, false when the number is even*/
bool primality(size_t n)
{
    size_t i = 2;

    while(i*i < n)
    {
        if(n%i == 0)
            return false;
        ++i;
    }
    return true;
}

/*Funcion que guarda secuencialmente cuantas veces se repite en un arrays de [0 a n]
    vector<int> v= {0,0,4,2,4,5};
    assertV(result,{2,0,1,0,2,1});
*/
vector<int> countElement(vector<int>& A)
{
    vector<int> count(A.size(),0u);

    for(auto i =0u; i< A.size(); ++i)
        count[A[i]] += 1u;

    return count;
}

/* Funcion que suma los elementos consecutivamente hasta A.size()+1 donde p[0] siempre sera cero:
 *  vector<int> v= {2,3,7,5,1,3,9};
    assertV(result,{0,2,5,12,17,18,21,30});
*/
vector<int> prefixSums(vector<int>& A)
{
    vector<int> p(A.size()+1u,0);

    for(auto i = 1u; i <p.size(); ++i)
        p[i]=p[i-1]+A[i -1];

    return p;
}

/* Acomodo por O(n2)
    vector<int> v= {2,3,7,5,1,3,9};
    assertV(v,{1,2,3,3,5,7,9});*/
void selectionSort(vector<int>& A)
{
    int minimal = 0u;

    /* Itera todo el contenedor, indice contiene el elemento siguiente al que esta ordenado*/
    for(auto k = 0u; k< A.size();++k)
    {
        minimal = k;
        /* Itera los elementos no ordenados hasta encontrar un valor minimo al nuevo para ordenar*/
        for(auto j = k + 1; j < A.size(); ++j)
            if(A[j] < A[minimal])
                minimal = j;
        swap(A[k],A[minimal]);
    }
}

/* Acomodo por O(n+k)
    vector<int> v= {2,3,7,5,1,3,9};
    assertV(v,{1,2,3,3,5,7,9});*/
void countingSort(vector<int>& A)
{
    vector<int> count = countElement(A);

    int p=0;

    /* Itera los contadores de cada elemento de A, el indice i es el elemento que se esta buscando,
        y cuando se itera en j, se esta buscando cuantas veces es repetido en A para ser ordenado consecutivamente.*/
    for(auto i=0u ; i< count.size()+1; ++i)
        for(auto j=0; j < count[i]; ++j)
        {
            A[p]=i;
            p+=1;
        }
}

/*O(n)
    mergeSort(v,0,v.size()-1);
    assertV(v,{1,2,3,3,5,7,9});
*/
void merge(vector<int>& A, int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2= r-m;

    vector<int> L(n1);
    vector<int> R(n2);

    for(i = 0u; i<n1; ++i)
        L[i] =A[l+i];
    for(j = 0; j< n2; ++j)
        R[j] = A[m+1+j];

    i=0;
    j=0;
    k=l;

    /*Ordenar para A los subsets de Left y Right array.*/
    while(i<n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            A[k]= L[i];
            ++i;
        }
        else
        {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }

    /*Setear los elementos remanentes de Left*/
    while(i<n1)
    {
        A[k]=L[i];
        ++i;
        ++k;
    }
    /*Setear los elementos remanentes de Right*/
    while(j<n2)
    {
        A[k]= R[j];
        ++j;
        ++k;
    }
}
void mergeSort(vector<int>& A, int l, int r)
{
    if(l<r)
    {
        int m= l+(r-l)/2;

        mergeSort(A,l,m);
        mergeSort(A,m+1,r);

        merge(A,l,m,r);
    }
}

/*Assertion de vectores de ints*/
void assertV( vector<int>& result,  vector<int>&& comp)
{
    bool res = std::equal(result.begin(),result.end(),comp.begin());
    assert(res);
}

/*Imprimir vector<int>s*/
void printV(const vector<int>& vRes)
{
    for(auto it= vRes.begin(); it != vRes.end();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

/*O(n logn) busqueda de Lider
    vector<int> v= {4,6,6,6,6,8,8,8,8,8,8,8};
    assert(result==8);*/
int fastLeader(vector<int>& A)
{
    int leader = -1;

    sort(A.begin(),A.end());
    int candidate = A[A.size()/2];
    auto count =0u;

    for(auto i = 0u; i< A.size();++i)
        if(A[i]== candidate)
            count++;
    if(count> A.size()/2)
        leader=candidate;

    return leader;
}

/*O(n) busqueda de Lider
    vector<int> v= {4,6,6,6,6,8,8,8,8,8,8,8};
    assert(result==8);*/
int goldenLeader(vector<int>& A)
{
    int size =0;
    int value = 0;

    for(auto k=0u; k<A.size(); ++k)
    {
        if(0u == size)
        {
            size++;
            value = A[k];
        }
        else
        {
            if(A[k] != value)
                size--;
            else
                size++;
        }
    }

    int candidate = -1;

    if(size>0)
        candidate=value;

    int leader = -1;
    auto count =0u;

    for(auto k=0u;k< A.size();++k)
     if(A[k] == candidate)
         count++;

    if(count > A.size()/2)
        leader= candidate;

    return leader;
}

/*
 max_slide retorna el numero maximo en un rango [p,q] del arreglo.
*/
int max_slide(vector<int>& A)
{
    int max_slide, max_ending = 0;

    for(auto a: A)
    {
        /* Suma consecutiva que ignora cualquier "a" que reste a la suma*/
        max_ending = max(0, max_ending + a);
        max_slide = max(max_slide,max_ending);
    }
    return max_slide;
}

/*Shift aritmetico hacia la derecha
    int result = arithShift(20,2);
    assert(result==5);*/
int arithRightShift(int x, int count)
{
    for(auto i=0; i< count; i++)
        x>>=1;
    return x;
}

/*Shift aritmetico hacia la derecha
    int result = arithShift(20,2);
    assert(result=80);*/
int arithLeftShift(int x, int count)
{
    for(auto i=0; i< count; i++)
        x<<=1;
    return x;
}

/*Get the bit value of the ith position from num*/
bool getBit(int num, int i)
{
    return ((num & (1<<i)) != 0);
}

/*Set the bit value of the ith position from num*/
int setBit(int num,int i)
{
    return num | (1<<i);
}

/*Limpiar los bits desde 0 a i de num
    10100 -> 10000 2 bits +1
    int result = clearBit(20,2);
    assert(result==5);*/
int clearBit(int num, int i)
{
    int mask =~(1<<i);
    return num&mask;
}

/*Limpiar bits del mas significativo a i inclusivamente*/
int clearBitsMSBthroughI(int num, int i)
{
    int mask=(1<<i)-1;
    return num&mask;
}

/*Limpiar bits de I al menos signiticativo*/
int clearBitsIthrough0(int num, int i)
{
    int mask=(-1<<(i+1));
    return num&mask;
}

/* Setear el bit ith con un valor bitIs1 unicamente*/
int updateBit(int num, int i, bool bitIs1)
{
    int value=bitIs1?1:0;
    int mask=~(1<<i);
    return (num&mask)|(value<<i);
}

int main()
{
    vector<int> v= {4,6,6,6,6,8,8,8,8,8,8,8};

    /* 10100 -> 10000 2 bits +1*/
    int result = clearBit(20,2);
    cout<<result<<endl;
    assert(result==5);

    return 0;
}
