/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:36:18 by wchen             #+#    #+#             */
/*   Updated: 2022/12/20 20:26:58 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifdef BUFFER_SIZE
# else
#  define BUFFER_SIZE 1024
# endif

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
}			t_queue;

typedef struct s_ft_strtrim
{
	size_t			len_r_chr;
	char			*r_chr;
	size_t			first;
	size_t			last;
	size_t			i;
}					t_ft_strtrim;

t_node	*ft_lstnew(void *content);
void	ft_lstadd_front(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstdelone(t_node *lst, void (*del)(void *));
void	ft_lstclear(t_node **lst, void (*del)(void*));
void	ft_lstiter(t_node *lst, void (*f)(void *));
t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *c);
void	*ft_memset(void *buf, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);
int		ft_printf(const char *format, ...);
int		print_char(int chr);
int		print_str(char *str);
int		print_int(int integer);
int		print_unint(unsigned int un_int);
int		print_x(unsigned int un_int);
int		print_bx(unsigned int un_int);
int		print_ptr(unsigned long long uint_ptr);
t_queue	*ft_create_queue(void);
void	ft_enqueue(t_queue *q, void *content);
void	ft_dequeue(t_queue *q);
void	merge_sort(t_node **headRef);
void	ft_lst_ascsort(t_node **headRef);
void	ft_lst_descsort(t_node **headRef);

#endif
