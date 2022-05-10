/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkansoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:37:57 by zkansoun          #+#    #+#             */
/*   Updated: 2022/04/21 13:13:33 by zkansoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef unsigned int	t_size;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(long long value);
size_t		ft_number_of_digits(long long value);
size_t		ft_to_hexa(unsigned long adress, char c);
void		ft_print_no_spec(const char *s, size_t *charnbr);
const char	*ft_print_integer(const char *s, size_t *charnbr, int value);
const char	*ft_print_unint(const char *s, size_t *charnbr, unsigned int value);
const char	*ft_print_adress(const char *s, size_t *charnbr, unsigned long adr);
const char	*ft_print_hexa_x(const char *s, size_t *charnbr, unsigned int val);
const char	*ft_print_charac(const char *s, size_t *charnbr, char c);
const char	*ft_print_string(const char *s, size_t *charnbr, char *str);
const char	*ft_print_perc(const char *s, size_t *charnbr);
const char	*ft_specifier(const char *s, va_list all_args, size_t *charnbr);
int			ft_printf(const char *s, ...);
int			ft_count_for_hexa(unsigned long adress);
#endif
