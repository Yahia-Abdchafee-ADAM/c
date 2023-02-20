int attack_value(char *attack)
{
    int attack_value = 18;

    int c = -64 + attack[0];
    int i = -48 + attack[1];

    attack_value = attack_value + i * 18 + (c * 2); 
    return (attack_value);
}
