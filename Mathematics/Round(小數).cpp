double myround(double number, unsigned int bits)
{
    LL integerPart = number;
    number -= integerPart;
    for (unsigned int i = 0; i < bits; ++i)
        number *= 10;
    number = (LL)(number + 0.5);
    for (unsigned int i = 0; i < bits; ++i)
        number /= 10;
    return integerPart + number;
}
//printf("%.1f\n", round(3.4515239, 1));