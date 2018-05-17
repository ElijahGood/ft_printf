/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazarin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:56:58 by inazarin          #+#    #+#             */
/*   Updated: 2018/03/22 17:13:59 by inazarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define DIOUX(x) (x == 'd' || x == 'i' || x == 'x' || x == 'o' || x == 'u')
# define DOUX(x) (x == 'D' || x == 'U' || x == 'O' || x == 'X')
# define CCSS(x) (x == 'c' || x == 's' || x == 'C' || x == 'S')
# define WIDTH(x) (x == '*' || (x >= '1' && x <= '9'))
# define FLAGS(x) (x == '#' || x == '0' || x == '-' || x == '+' || x == ' ')
# define LONGS(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')

# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

union				u_n
{
	int				i;
	long int		li;
	long long int	lli;
	unsigned int	u;
	unsigned long	uli;
	unsigned long	ulli;
	short int		sh;
	unsigned short	ush;
	char			c;
	unsigned char	uc;
	char			*s;
	intmax_t		im;
	uintmax_t		uim;
	size_t			st;
	ssize_t			sst;
}					u_n;

typedef	struct		s_prf
{
	union u_n		u_n;
	int				pre;
	int				wid;
	int				holder;
	int				zero;
	int				plus;
	int				minus;
	int				hash;
	int				space;
	int				dioux;
	int				doux;
	int				octal;
	int				sign;
	int				wipre;
	int				decrem;
	int				dcrmnt;
	int				minsign;
	int				hex;
	int				null;
	int				counter;
	int				dot;
	int				unicount;
}					t_prf;

int					write_d_help_d(t_prf *pf, int *res, int *un, int len);
void				write_d_help_fin(t_prf *pf, int *res, int *un, char *s);
void				write_big_x_help(t_prf *pf, int *res, int *un, int len);
void				write_x_help(t_prf *pf, int *res, int *un, int len);
void				write_u_help(t_prf *pf, int *res, int *un, int len);
void				write_o_help(t_prf *pf, int *un, int len, int *res);
void				initialize_prf(t_prf *pf);
int					ft_dec_to_bin(unsigned int i);
int					unichr_write(unsigned int v, int res);
int					unistr_write(va_list ap, int res, t_prf *pf, int un);
void				prec_counter(const char **format, va_list ap, t_prf *pf);
int					precision_write(t_prf *pf, int res, int un, int len);
void				wid_handle(const char **format, va_list ap, t_prf *pf);
int					wid_write(t_prf *pf, int res, int un, int len);
int					write_p(va_list ap, t_prf *pf, int res);
int					write_x(va_list ap, t_prf *pf, int res, int un);
int					write_o(va_list ap, t_prf *pf, int res, int un);
int					write_u(va_list ap, t_prf *pf, int res, int un);
int					write_d_help(t_prf *pf, int len, int un, int *res);
int					write_d(va_list ap, t_prf *pf, int res, int un);
int					dioux(const char *format, va_list ap, t_prf *pf, int res);
int					write_ld(va_list ap, t_prf *pf, int res, int un);
int					write_lo(va_list ap, t_prf *pf, int res, int un);
int					write_lu(va_list ap, t_prf *pf, int res, int un);
int					write_big_x(va_list ap, t_prf *pf, int res, int un);
int					doux(const char *format, va_list ap, t_prf *pf, int res);
int					write_s(va_list ap, t_prf *pf, int res, int un);
int					write_c(int c, t_prf *pf, int res);
int					sscc(const char *format, va_list ap, t_prf *pf, int res);
int					write_lld(va_list ap, t_prf *pf, int res, int un);
int					write_llo(va_list ap, t_prf *pf, int res, int un);
int					write_llu(va_list ap, t_prf *pf, int res, int un);
int					write_llx(va_list ap, t_prf *pf, int res, int un);
int					write_ll_big_x(va_list ap, t_prf *pf, int res, int un);
int					write_lx(va_list ap, t_prf *pf, int res, int un);
int					write_l_big_x(va_list ap, t_prf *pf, int res, int un);
int					l_handl(const char **form, va_list ap, t_prf *pf, int res);
int					write_hhd(va_list ap, t_prf *pf, int res, int un);
int					write_hho(va_list ap, t_prf *pf, int res, int un);
int					write_hhu(va_list ap, t_prf *pf, int res, int un);
int					write_hhx(va_list ap, t_prf *pf, int res, int un);
int					write_hh_big_x(va_list ap, t_prf *pf, int res, int un);
int					write_hd(va_list ap, t_prf *pf, int res, int un);
int					write_ho(va_list ap, t_prf *pf, int res, int un);
int					write_hu(va_list ap, t_prf *pf, int res, int un);
int					write_hx(va_list ap, t_prf *pf, int res, int un);
int					h_handl(const char **form, va_list ap, t_prf *pf, int res);
int					write_zd(va_list ap, t_prf *pf, int res, int un);
int					write_zo(va_list ap, t_prf *pf, int res, int un);
int					write_zu(va_list ap, t_prf *pf, int res, int un);
int					write_zx(va_list ap, t_prf *pf, int res, int un);
int					write_z_big_x(va_list ap, t_prf *pf, int res, int un);
int					z_handl(const char **form, va_list ap, t_prf *pf, int res);
int					write_jd(va_list ap, t_prf *pf, int res, int un);
int					write_jo(va_list ap, t_prf *pf, int res, int un);
int					write_jx(va_list ap, t_prf *pf, int res, int un);
int					write_j_big_x(va_list ap, t_prf *pf, int res, int un);
int					j_handl(const char **form, va_list ap, t_prf *pf, int res);
int					sp_hand(const char **form, va_list ap, t_prf *pf, int res);
int					easy_wr(const char *form, va_list ap, t_prf *pf, int res);
int					flags(const char *format, t_prf *pf, int res);
int					parsing(const char **form, va_list ap, t_prf *pf, int res);
int					parsedata(const char *form, va_list ap, t_prf pf, int res);
int					write_ll_big_d(va_list ap, t_prf *pf, int res, int un);
int					write_hh_big_o(va_list ap, t_prf *pf, int res, int un);
int					write_h_big_d(va_list ap, t_prf *pf, int res, int un);
int					write_h_big_x(va_list ap, t_prf *pf, int res, int un);
char				*ft_itoa_b_s(intmax_t n, int base);
char				*ft_itoa_b_u(uintmax_t n, int base);
char				*ft_itoa_b_u_up(uintmax_t n, int base);
char				*ft_itoa_b_u_l(unsigned int nbr, int base);
char				*ft_itoa_base_u(unsigned int nbr, int base);
char				*ft_itoa_base(unsigned long long nbr, int base);
char				*ft_itoa_b_l(unsigned long long int nbr, int base);
int					ft_printf(const char *format, ...);

#endif
