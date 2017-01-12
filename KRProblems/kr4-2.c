#include <ctype.h>
#include <math.h>

double myatof(char s[])
{
	double val, power;
	int i, sign;

	for(i = 0; isspace(s[i]); i++)
	{
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
	{
		i++;
	}
	for(val = 0.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
	}
	if(s[i] == '.')
	{
		i++;
	}
	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	double tenspower = 0;
	int tensign = 1;
	if(s[i] == 'e')
	{
		i++;
	}
	if(s[i] == '-')
	{
		tensign = -1;
		i++;
	}
	for(tenspower = 0.0; isdigit(s[i]); i++)
	{
		tenspower = 10.0 * tenspower + (s[i] - '0');
	}
	double sci_scal;
	for(sci_scal = 1.0; tenspower > 0; tenspower--)
	{
		sci_scal *= 10.0;
	}
	if(tensign < 0)
	{
		sci_scal = 1 / sci_scal;
	}
	return sign * sci_scal * val / power;
}
