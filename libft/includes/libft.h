/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:19:49 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/17 07:45:01 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "printf.h"
# include "get_next_line.h"
# include "bigint.h"
# define ABS(v) (v < 0 ? (v * -1) : v)
# define SIGN(v) (v >= 0 ? 1 : -1)
# define BETWEEN(v,v1,v2) (v >= v1 && v<= v2)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_iswhitespace(char c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			buble_sort(int *t, size_t size, bool asc);
bool			ft_find_int(int *t, int n, size_t size, size_t *index);
int				ft_declen(long long int s);
char			*ft_itoa(long long nb);
char			*ft_itoa_base(long long n, int base);
int				ft_isdigit(int c);
char			*ft_uitoa(unsigned long long n);
char			*ft_uitoa_base(unsigned long long n, int base);
int				ft_int_min(int *tab, size_t size);
int				ft_max(int a, int b);
int				ft_int_max(int *tab, size_t size);
long long		ft_pow(long long n, int p);
int				ft_sqrt(int s);
bool			ft_swap(int *a, int *b);
bool			ft_isnbr(const char *s);
bool			is_sorted_desc(int *t, size_t size);
bool			is_sorted_asc(int *t, size_t size);
bool			int_rrot(int *t, size_t size);
bool			int_rot(int *t, size_t size);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

long long		ft_atoi(const char *s);
long long		ft_atoi_base(const char *s, const char *s_base, int base);
int				ft_isinstr(char c, const char *s);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *dest, const char *src, size_t nb);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtoupper(char *str);
char			*ft_realloc(char *str, size_t new_size);
char			*ft_skipchr(const char *s, char c);
char			*ft_skipnchr(const char *s, int i);
char			*ft_skip_chars(char *str, const char *compare);
char			*ft_skip_unitl_char(char *str, const char *compare);
int				ft_strindexof(const char *s, char c);
char			*ft_strreplace(char *str, char find, char replace);
int				ft_str_occurence(char *str, char c);
void			ft_strreplaceall(char *str, char find, char replace);
int				ft_wordcount(const char *str, char c);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelfn(void *obj, size_t size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_printbit(size_t n, int size);
__uint64_t		ft_reverse_bits(__uint64_t n, int size);

int				get_next_line(const int fd, char **line);
void			ft_die(const char *message, int error_nb);

int				ft_printf(const char *restrict fmt, ...);

_Bool			ft_flag_is_active(char c, long long flags);
_Bool			ft_set_flags(char *str, long long *flags);

#endif
