#include "ft_printf.h"

static void	ft_wid_ulln(t_struct *data, unsigned long long int n)
{
	if (data->wid > (long long int)data->size && data->zero == '0')
	{
		if (data->plus != 0)
			data->nb_char += write(1, &data->plus, 1);
		data->nb_char += ft_put_mult('0', (data->wid - data->size));
		data->nb_char += ft_putulln(n);
	}
	else if (data->wid > (long long int)data->size)
	{
		data->nb_char += ft_put_mult(' ', data->wid - data->size);
		if (data->plus != 0)
			data->nb_char += write(1, &data->plus, 1);
		if (data->acc > data->nblen)
			data->nb_char += ft_put_mult('0', data->acc - data->nblen);
		data->nb_char += ft_putulln(n);
	}
	else
	{
		if (data->plus != 0)
			data->nb_char += write(1, &data->plus, 1);
		if (data->acc > data->nblen)
			data->nb_char += ft_put_mult('0', data->acc - data->nblen);
		data->nb_char += ft_putulln(n);
	}
}

static void	ft_wid_ullnm(t_struct *data, unsigned long long int n)
{	
	if (data->zero == '0')
		data->zero = 32;
	if (data->plus != 0)
		data->nb_char += write(1, &data->plus, 1);
	if (data->acc > data->nblen)
		data->nb_char += ft_put_mult('0', data->acc - data->nblen);
	data->nb_char += ft_putulln(n);
	if (data->wid > data->size)
		data->nb_char += ft_put_mult(' ', data->wid - data->size);
}

void	ft_print_int(t_struct *data, long long int n)
{
	if (data->acc == -1)
		data->acc++;
	else
		data->zero = 32;
	if (data->plus != 0 || n < 0)
		data->size++;
	if (n < 0)
	{
		n = -n;
		data->plus = '-';
	}
	data->nblen = ft_unblen((unsigned long long int)n);
	if ((data->size = data->nblen) < data->acc)
		data->size = (size_t)data->acc;
	if (data->plus != 0 || n < 0)
		data->size++;
	if (n < 0)
	{
		n = -n;
		data->plus = '-';
	}
	data->moins == 0 ? \
	ft_wid_ulln(data, (unsigned long long int)n) : \
	ft_wid_ullnm(data, (unsigned long long int)n);
}

void	ft_print_uint(t_struct *data, unsigned long long int n)
{
	data->nblen = ft_unblen(n);
	if (data->acc == -1)
		data->acc++;
	else
		data->zero = 32;
	if ((data->size = data->nblen) < data->acc)
		data->size = (size_t)data->acc;
	if (data->plus != 0)
		data->size++;
	data->moins == 0 ? \
	ft_wid_ulln(data, n) : \
	ft_wid_ullnm(data, n);
}
