/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:33:48 by ilyanar           #+#    #+#             */
/*   Updated: 2024/05/12 21:25:24 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h> 
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

//	libft

//	copies 'n' bytes from memory area 'src' to memory area 'dst'.
void	*ft_memcpy(void *dst, const void *src, size_t n);
//	 copies 'len' bytes from string 'src' to string 'dst'. the two strings may
//	 overlap. The copy is always done in a non-destructive manner.
void	*ft_memmove(void *dst, const void *src, size_t len);
//	 locates the first occurrence of 'c'
//	 (converted to an unsigned char) in string 's'.
void	*ft_memchr(const void *s, int c, size_t n);
//	writes 'len' bytes of value 'c' (converted to an unsigned char)
//	to the string 'b'.
void	*ft_memset(void *b, int c, size_t len);
//	Allocates enough space for count objects that are size bytes of memory.
//	Each and returns a pointer to the allocated memory.
//	The allocated memory is filled with bytes of value zero.
void	*ft_calloc(size_t count, size_t size);
//	Applies the 'f' function to each character
//	in the character string passed as argument.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//	Writes the integer 'n' to the file descriptor given.
void	ft_putnbr_fd(int n, int fd);
//	Outputs the string ’s’ to the given file descriptor followed by a newline.
void	ft_putendl_fd(char *s, int fd);
//	Outputs the string ’s’ to the given file descriptor.
void	ft_putstr_fd(char *s, int fd);
//	Writes 'n' zeroed bytes to the string 's'.
void	ft_bzero(void *s, size_t n);
//	Reverse the content of the string tab.
void	ft_rev_tab(char *tab);
//	Writes the integer 'n' with the given (char *)base.
void	ft_putnbr_base(unsigned int nb, char *base);

//	Outputs the char ’c’ to the given file descriptor.
int		ft_putchar_fd(char c, int fd);
//	Converts the initial portion of the 
//	string pointed to by 'str' to int representation.
int		ft_atoi(const char *str);
//	Return the number of occurence of (char)c in (char *)str.
int		count_char(char *str, char c);
//	return (1) if 'c' is a alpha caractere, else return (0).
int		ft_isalpha(int c);
//	return (1) if 'c' is a digit caractere, else return (0).
int		ft_isdigit(int c);
//	return (1) if 'c' is a alpha/num caractere, else return (0).
int		ft_isalnum(int c);
//	return (1) if 'c' is a  caractere, else return (0).
int		ft_isascii(int c);
//	return (1) if 'c' is a ascii(>= 0 && <= 127) caractere, else return (0).
int		ft_isprint(int c);
//	If 'c' is a lowercase letter convert it to capital letter and return it.
int		ft_tolower(int c);
//	If 'c' is a capital letter convert it to lowercase letter and return it.
int		ft_toupper(int c);
//	Compares byte string s1 against byte string s2.
//	Both strings are assumed to be n bytes long.
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//	lexicographically compare the null-terminated strings s1 and s2.
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// 
int		ft_free_tab(char ***tab);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

char	**ft_split(char const *s, char c);
char	**ft_strr_realloc(char **str, char *neww);
char	*ft_joint_all(char **str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *neww);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *neww);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));

//	printf.h

void	printf_base_addr(unsigned long long int nb, char *base, int *n);
void	stlen(char *tab, int *nb, char c, const char *str);
void	ft_putchar(char c, int *nb);
void	ft_putnbr(int nb, int *n);

int		who_is_char(const char *str, va_list *args, int *nb);
int		ft_printf(const char *str, ...);

//	GNL

char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
char	*get_next_line(int fd);

void	*gnl_calloc(size_t count, size_t size);
void	*gnl_memcpy(void *dst, const void *src, size_t n);

size_t	gnl_strlen(const char *s);

#endif
