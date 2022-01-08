#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum ExpT
{
    EXP_CONSTANT,
    EXP_PLUS,
    EXP_MINUS,
    EXP_MULT,
    EXP_DIV,
    EXP_SIN,
    EXP_COS,
    EXP_TAN,
    EXP_VARIABLE
} ExpType;



typedef struct Exp_str
{
    ExpType tipo;
    union
    {
        double value; // constants
        struct
        {
            struct Exp_str *Arg1, *Arg2; // binarias
        } binary;
        struct
        {
            struct Exp_str *Arg1; // unarias
        } unary;
    } args;
}*Exp;


//Imprime la expresion en forma legible
void PrintEXP(Exp expr);
// Evalúe la expresión, en el valor de la variable X
double Evaluate(Exp expr, double X);
// Libere todos los recursos asociados a expr.
void Destroy(Exp expr);
// Calcule la expresión derivada analítica de la expresión
Exp Derivate(Exp expr);
// Cree y retorne una expresión binaria
Exp CreateBinaryEXP(ExpType type, Exp expr1, Exp expr2);
// Cree y retorne una expresión unaria
Exp CreateUnaryEXP(ExpType type, Exp expr1);
// Cree y retorne una expresión constante
Exp CreateConstEXP(double value);
// Cree y retorne una expresión de variable
Exp CreateVarEXP();
// Cree y retorne un clon de la expresión recibida
Exp CloneEXP(Exp e);



int main()
{
double X=0;
PrintEXP(CreateBinaryEXP(EXP_DIV,CreateUnaryEXP(EXP_SIN,CreateBinaryEXP(EXP_PLUS,CreateBinaryEXP(EXP_MULT,CreateConstEXP(3),CreateVarEXP(X)),CreateConstEXP(4))),CreateBinaryEXP(EXP_PLUS,CreateConstEXP(2),CreateUnaryEXP(EXP_COS,CreateBinaryEXP(EXP_DIV,CreateVarEXP(X),CreateBinaryEXP(EXP_PLUS,CreateConstEXP(2),CreateVarEXP(X)))))));
printf("\n");
//PrintEXP(Derivate(CreateBinaryEXP(EXP_MULT,CreateUnaryEXP(EXP_COS,CreateConstEXP(1)),CreateConstEXP(1))));
}


void PrintEXP(Exp expr)
{
    switch (expr->tipo)
    {
    case EXP_CONSTANT:
        printf("%lf",expr->args.value);
        return;
    case EXP_PLUS :
        PrintEXP(expr->args.binary.Arg1);
        printf("+");
        PrintEXP(expr->args.binary.Arg2);
        return;
    case EXP_MINUS:
        PrintEXP(expr->args.binary.Arg1);
        printf("-");
        PrintEXP(expr->args.binary.Arg2);
        return;
    case EXP_MULT :
        PrintEXP(expr->args.binary.Arg1);
        printf("*");
        PrintEXP(expr->args.binary.Arg2);
        return;
    case EXP_DIV  :
        PrintEXP(expr->args.binary.Arg1);
        printf("/");
        PrintEXP(expr->args.binary.Arg2);
        return;
    case EXP_COS:
        printf("cos(");
        PrintEXP(expr->args.unary.Arg1);
        printf(")");
        return;
    case EXP_SIN:
        printf("sin(");
        PrintEXP(expr->args.unary.Arg1);
        printf(")");
        return;
    case EXP_TAN:
                printf("tan(");
        PrintEXP(expr->args.unary.Arg1);
        printf(")");
        return;
    case EXP_VARIABLE:
                printf("x");
    return;
    }
}

double Evaluate(Exp expr, double X)
{
    switch(expr->tipo)
    {
    case EXP_CONSTANT:
        return expr->args.value;
    case EXP_PLUS :
        return Evaluate(expr->args.binary.Arg1,X) + Evaluate(expr->args.binary.Arg2,X);
    case EXP_MINUS:
        return Evaluate(expr->args.binary.Arg1,X)-Evaluate(expr->args.binary.Arg2,X);
    case EXP_MULT :
        return Evaluate(expr->args.binary.Arg1,X)*Evaluate(expr->args.binary.Arg2,X);
    case EXP_DIV  :
        return Evaluate(expr->args.binary.Arg1,X)/Evaluate(expr->args.binary.Arg2,X);
    case EXP_COS:
        return sin(Evaluate(expr->args.unary.Arg1,X));
    case EXP_SIN:
        return sin(Evaluate(expr->args.unary.Arg1,X));
    case EXP_TAN:
        return tan(Evaluate(expr->args.unary.Arg1,X));
    case EXP_VARIABLE:
        return X;
    }
}

void Destroy(Exp expr)
{
        switch(expr->tipo)
    {
    case EXP_CONSTANT:
        free(expr);
        return;
    case EXP_PLUS :
        Destroy(expr->args.binary.Arg1);
        Destroy(expr->args.binary.Arg2);
        return;
    case EXP_MINUS:
        Destroy(expr->args.binary.Arg1);
        Destroy(expr->args.binary.Arg2);
        return;
    case EXP_MULT :
        Destroy(expr->args.binary.Arg1);
        Destroy(expr->args.binary.Arg2);
        return;
    case EXP_DIV  :
        Destroy(expr->args.binary.Arg1);
        Destroy(expr->args.binary.Arg2);
        return;
    case EXP_COS:
        Destroy(expr->args.binary.Arg1);
        return;
    case EXP_SIN:
        Destroy(expr->args.binary.Arg1);
        return;
    case EXP_TAN:
        Destroy(expr->args.binary.Arg1);
        return;
    case EXP_VARIABLE:
        free(expr);
        return;
}
}

Exp Derivate(Exp expr)
{

            switch(expr->tipo)
    {
    case EXP_CONSTANT:
        return CreateConstEXP(0);
    case EXP_PLUS :
        return CreateBinaryEXP(EXP_PLUS,Derivate(expr->args.binary.Arg1),Derivate(expr->args.binary.Arg2));
    case EXP_MINUS:
        return CreateBinaryEXP(EXP_MINUS,Derivate(expr->args.binary.Arg1),Derivate(expr->args.binary.Arg2));
    case EXP_MULT :
        return CreateBinaryEXP(EXP_PLUS,CreateBinaryEXP(EXP_MULT,Derivate(expr->args.binary.Arg1),CloneEXP(expr->args.binary.Arg2)),CreateBinaryEXP(EXP_MULT,CloneEXP(expr->args.binary.Arg1),Derivate(expr->args.binary.Arg2)));
    case EXP_DIV  :
        return CreateBinaryEXP(EXP_DIV     ,
                                   CreateBinaryEXP(   EXP_MINUS,CreateBinaryEXP(EXP_MULT,Derivate(expr->args.binary.Arg1),CloneEXP(expr->args.binary.Arg2)),CreateBinaryEXP(EXP_MULT,CloneEXP(expr->args.binary.Arg1),Derivate(expr->args.binary.Arg2)))
                                                    ,CreateBinaryEXP(EXP_MULT,CloneEXP(expr->args.binary.Arg2),CloneEXP(expr->args.binary.Arg2)))     ;
    case EXP_COS:
       return CreateBinaryEXP(EXP_MULT       ,      CreateUnaryEXP(EXP_SIN,expr->args.unary.Arg1)         ,     CreateConstEXP(-1)   )    ;
    case EXP_SIN:
        return CreateUnaryEXP( EXP_COS,CloneEXP(expr->args.unary.Arg1));
    case EXP_TAN:
         return CreateBinaryEXP( EXP_DIV    , CreateConstEXP(1),CreateBinaryEXP(EXP_MULT,CreateUnaryEXP(EXP_COS,expr->args.binary.Arg1),CreateUnaryEXP(EXP_COS,expr->args.binary.Arg1)));
    case EXP_VARIABLE:
        return CreateConstEXP(1);

}
}


Exp CreateBinaryEXP(ExpType type, Exp expr1, Exp expr2)
{
    Exp expr;
    expr=malloc(sizeof(struct Exp_str));

    expr->tipo=type;
    expr->args.binary.Arg1=expr1;
    expr->args.binary.Arg2=expr2;

    return expr;
}

Exp CreateUnaryEXP(ExpType type, Exp expr1)
{
    Exp expr;
    expr=malloc(sizeof(struct Exp_str));
    expr->tipo=type;
    expr->args.binary.Arg1=expr1;
    return expr;
}

Exp CreateConstEXP(double value)
{
    Exp expr;
    expr=malloc(sizeof(struct Exp_str));
    expr->tipo=EXP_CONSTANT;
    expr->args.value=value;
    return expr;
}

Exp CreateVarEXP()
{
    Exp expr;
    expr=malloc(sizeof(struct Exp_str));
    expr->tipo=EXP_VARIABLE;
    return expr;
}


Exp CloneEXP(Exp e)
{
    Exp expr;
    expr=malloc(sizeof(struct Exp_str));
    expr->tipo=e->tipo;
    switch(e->tipo)
    {
        case EXP_CONSTANT:
        expr->tipo=e->tipo;
        expr->args.value=e->args.value;
        return;
        case EXP_PLUS:
        expr->args.binary.Arg1=e->args.binary.Arg1;
        expr->args.binary.Arg1=e->args.binary.Arg2;
        return;
        case EXP_MINUS:
        expr->args.binary.Arg1=e->args.binary.Arg1;
        expr->args.binary.Arg1=e->args.binary.Arg2;
        return;
        case EXP_MULT:
        expr->args.binary.Arg1=e->args.binary.Arg1;
        expr->args.binary.Arg1=e->args.binary.Arg2;
        return;
        case EXP_DIV:
        expr->args.binary.Arg1=e->args.binary.Arg1;
        expr->args.binary.Arg1=e->args.binary.Arg2;
        return;
        case EXP_SIN:
        expr->args.binary.Arg1=e->args.binary.Arg1;
        return;
        case EXP_COS:
        expr->args.binary.Arg1=e->args.binary.Arg1;
        return;
        case EXP_TAN:
        expr->args.binary.Arg1=e->args.binary.Arg1;
        return;
    }
    return expr;
}
