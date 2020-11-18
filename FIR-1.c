#include<stdio.h>
#include<math.h>

int filterSpec();
double lpKoef();
double bpKoef();

float dp, ds, df;
int ftype;

int main(int argc, char const *argv[])
{
    double N;

    ftype = filterSpec(); 
    
    switch (ftype)
    {
    case 1:
        printf("Lowpass filter calculating...\n");
        N = lpKoef();
        break;
    case 2:
        printf("Bandpass filter calculating...\n");
        N = bpKoef();
    }

    printf("    1.  The number of koeficients: \t%f\n", N);
    printf("    2.  Bandwidth deviation in dB: \t%f\n", dp);
    printf("    3.  Stopband  deviation in dB: \t%f\n", ds);

    return 0;
}


int filterSpec () {
   int type;
   printf("Filter type: type <1> to define LP or type <2> to define BP: ");
   scanf("%d", &type);
//    printf("\n");

   printf("Enter Bandwidth & Stopband ");
   printf("from 0.0 to 1.0.\n");
   printf("From | "); scanf("%f", &dp);
   printf("To   | "); scanf("%f", &ds);
   printf("\n");

   switch (type)
   {
   case 1:
       printf("Normalized transition bandwidth: ");
       scanf("%f", &df);
       break;
   case 2:
       printf("Less normalized transition bandwidth: ");
       scanf("%f", &df);
       break;
   }
   return (type);
}


double lpKoef() {
    float ddp, dds;
    double dinf, ff, NI;
    float a[6] = {0.005309, 0.07114, -0.4761, -0.00266, -0.5941, -0.4278};
    float b1 = 11.01217;
    float b2 = 0.5124401;

    ddp = log10(dp);
    dds = log10(ds);

    double t[4] = { (a[0] * ddp*ddp) , (a[1] * ddp) , (a[3] * ddp*ddp) , (a[4] * ddp)};

    dinf = ((t[0] + t[1] + a[2]) * dds + (t[2] * t[3] + a[5]));

    ff = b1 + b2 * (ddp - dds);
    NI = ((dinf / df) - (ff * df) + 1);
    dp = 20*log10(1 + dp); ds = -20*log10(ds);
    return NI;
}

double bpKoef() {
    float ddp, dds;
    double cinf, ginf, Nb; 
    float a[6] = {0.01201, 0.09664, -0.51325, 0.00203, -0.57054, -0.44314};

    ddp = log10(dp);
    dds = log10(ds);
    double t[4] = {(a[0] * ddp*ddp) , (a[1] * ddp) , (a[3] * ddp*ddp) , (a[4] * ddp)};
    
    cinf = dds * (t[0] + t[1] + a[2]) + t[2] + t[3] + a[5];
    ginf = -14.6 * log10(dp / ds) - 16.9;
    Nb = (cinf / df) + ginf*df+1;
    dp = 20*log10(1 + dp); ds = -20*log10(ds);
    return Nb;
}
