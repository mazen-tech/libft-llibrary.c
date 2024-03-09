#include<stddef.h>
#include<unistd.h>
#include<stdlib.h>
#include "libft.h"

//strlen
size_t  ft_strlen(const char *src)
{
    size_t i;
    
    i = 0;
    while (src[i] != '\0')
    {
        i++;
    }
    return (i);
}

//strlcpy
size_t      ft_strlcpy(char *dest, const char *src, size_t n)
{
    size_t i;
    
    i = 0;

    if (!n)
    {
        return (ft_strlen(src));
    }

    while (src[i] && i < (n-1))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}

//strlcat
size_t      ft_strlcat(char *dest, const char *src, size_t n)
{
    size_t i;//index of src
    size_t j;//indec of dest
    char *ptr;

    i = 0;
    j = 0;
    ptr = (char *)src;

    while (*dest && i < n)
    {//to iterate the loop and reach the end of dest
        dest++;
        i++;
    }

    if (i == n)
    {
        return((i + ft_strlen(dest)));
    }

    while (ptr[j])
    {
        if (j < (n - i - 1))
        { //n-i-1 to make sure the size of dest is enough and avoid overflow 
            *dest++ = ptr[j];
        }
        j++;
    }
    dest = '\0';
    return (i+j);

}

//atoi
int     ft_atoi(const char *str)
{
    int     i;// for unprintable chars
    int     r;// for posative
    int     s; 

    i = 0;
    r = 0;
    s = 1;

    while (str[i] == '\t' || str[i] == '\r' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
            i++;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            s *= -1;// n = n * -1 to convert it to negative
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
            r = r * 10 + (str[i] - '0');
            i++;
    }

    return (r * s);  
}

//toupper
char    ft_toupper(char c){

    if(c <= 'z' && c >= 'a')
    {
        c = c - ('a' - 'A');
        return (c);
    }
    else
    {
        return (c);
    }
}

//tolower
char    ft_tolower(char c)
{
    if (c <= 'Z' && c >= 'A')
    {
        c = c - ('A' - 'a');
        return (c); 
    }

    else
    {
        return (c);
    }
}

//strncmp
int     ft_strncmp(const char *s1,const char *s2, int n)
{
    int i;
    
    i = 0;
    while ((s1[i] != '\0' || s2[i] != '\0') && n > i)
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}

//strchr
char    *ft_strchr(const char *str, int c)
{
    char *ptr;
    
    ptr  = (char *)str;
    while (*ptr)
    {
        if (*ptr == (unsigned char) c)
            return (ptr);
        ptr++;
    }
    if (c == '\0')
        return (ptr);
    return (NULL);
}

//strrchr
char    *ft_strrchr(char *str, char c)
{
    int i;
    int last_index;
    
    i = 0;
    last_index = -1; //assumening that C has not been found yet 

    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            last_index = i;
        }
        i++;
    }

    if (last_index != -1)
    {
        return (&str[last_index]);
    }
    else
    {
        return (NULL);
    }
}

//bzero
void    ft_bzero(void *s, size_t n)
{
    unsigned char *sptr;
    
    sptr = s;//unsigned to ensure we working in rang of 0 - 255
    while (n)
    {//the loop will iteratre n time undet the n number of byte all sit to zero
        *sptr++ = 0; // we increment to every byte of memore and sit to zero
        n--;
    }
}

//memset
void    *ft_memset( void *s1, int c, size_t n)
{
    unsigned char *ptr;
    size_t i;
    
    ptr = (unsigned char *)s1;
    i = 0;
    while (i < n)
    {
        ptr[i] = c;
        i++;
    }
    return (s1);
}

//memchr
void    *ft_memchr(const void *arr, int c, size_t depth)
{
    
    unsigned char *ptr;
    
    ptr = (unsigned char *)arr;
    c = (unsigned char) c;

    while (*ptr != c && depth)
    {
        ptr++;
        depth--;
    }

    if (depth)
    {
        return ((void *)ptr);
    }
    else
    {
        return (NULL);
    }
}

//memcpy
void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    char *dptr;
    const char *sptr;

    i = 0;
    dptr = (char *)dest;
    sptr = (const char *)src;

    if (!src && !dest)
    {
        return (dest);
    }

    while (n > i)
    {
        dptr[i] = sptr[i];
        i++;
    }
    return (dest);
}

//memmove
void    *ft_memmove(void *dest, const void *src, size_t n)
{
    char *dprt;
    const char *sptr;

    dprt = (char *)dest;
    sptr = (const char *)src;

    if(!src && !dest)
    {
        return (dest);
    }

    if (dest < src)
    { //if the condetion is true that mean that src is higher in mem than dest
                    //which means that no overlapping withh take place 
        return (ft_memcpy(dest,src,n));
    }

    while (n--)
    { //we cant use i<n here cuz it will move the data in revears 
        dprt[n] = sptr[n];
    }
    return (dest);
}

//memcmp
int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *ps1;
    unsigned char *ps2;
    
    ps1 = (unsigned char *)s1;
    ps2 = (unsigned char *)s2;
    
    while (n && *ps1 == *ps2)
    {
        ps1++;
        ps2++;
        n--;
    }
    if (n)
    {
        return (*ps1 - *ps2);
    }
    else
    {
        return(0);
    }
}

//isdigit
int     ft_isdigit(int d)
{
    return ((d >= '0' && d <= '9'));
}

//isalpha
int     ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z')||(c >= 'A' && c <='Z'));
}

//isalnum
int     ft_isalnum(int n)
{
    return ((ft_isalpha(n) || ft_isdigit(n)));
}

//isascii
int     ft_isascii(int a)
{
    return(a >= 0 && a <= 127);
}

//isprint
int     ft_isprint(int p)
{
    return (p >= 32 && p <= 126);
}


//putchar_fd
void    ft_putchar_fd(char c, int fd)
{
    write (fd,&c,1);
}

//put_str_fd
void    ft_putstr_fd(char *s, int fd)
{
    if (!s)
    {
        return ;
    }
    write (fd, s, ft_strlen(s));
}

//putendl_fd
void    ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd (s,fd);
    write (fd,"\n",1);
}

//putnbr_fd
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

//calloc
void    *ft_calloc(size_t num, size_t size)
{
    void    *ptr;
    
    ptr = malloc(num * size);

    if (!ptr)
    {
        return (NULL);
    }

    ft_bzero (ptr,num*size);
    return (ptr);
}

//strdup
char    *ft_strdup(const void *str)
{
    size_t len;
    char *dest;
    
    len = ft_strlen(str)+1;
    dest = malloc(len);

    if (dest == NULL)
    {
        return (NULL);
    }

    ft_memcpy(dest,str,len);
    return (dest);
}

//strnstr
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

    n = ft_strlen(little);

	if (*little == 0)
    {
		return ((char *)big);
    }    
	
	if (len == 0)
    {
		return (0);
    }
	while (*big && n <= len)
	{
		if (*big == *little && ft_strncmp(big, little, n) == 0)
        {
			return ((char *)big);
        }    
		++big;
		--len;
	}
	return (NULL);
}

//substr
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t size; // size of remaining string after start

    if (!s)//if there is no big string return NULL
    {
        return (NULL);
    }

    if (start >= ft_strlen(s)) // that means the start out the rang of the big string
    {
        return(ft_strdup(""));
    }

    size = ft_strlen(s + start); //size of remaining with start is =  s + start 

    if (size < len)
    {//length of sub string > size of remaing start 
        len = size;//adgust 
    }

    sub = (char *)malloc(sizeof(char) * (len + 1));//resurving memory for sub string

    if (!sub)
    {
        return (NULL);
    }

    ft_strlcpy(sub, s + start, len + 1);
    return (sub);

}

//strjoin
char *ft_strjoin(char const *s1, char const *s2)
{
        char *dest;
        size_t len1;
        size_t len2;

        if (!s1 && !s2)
        {
            return (ft_strdup(""));
        }

        if (s1 && !s2)
        {
            return (ft_strdup(s1));
        }

        if (!s1 && s2)
        {
            return (ft_strdup(s2));
        }

        len1 = ft_strlen(s1);
        len2 = ft_strlen(s2);
        dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));

        if (!dest)
        {
            return (NULL);
        }

        ft_strlcpy(dest, s1, len1 + 1);
        ft_strlcat(dest , s2, len1 + len2 + 1);
        dest[len1 + len2] = '\0';
        return(dest);
}

//strtrim
char    *ft_strtrim(char const *s1, char const *set)
{
    char    *chrt;  // char that will be trimmed  
    size_t  start;
    size_t  end;
    
    start = 0;
    end = ft_strlen(s1) - 1;//-1 for the zero termenator
    if (!s1)
    {
     return (NULL);
    }

    if (!set)
    {
        return (ft_strdup(s1));
    }

    while (s1[start] && ft_strchr(set, s1[start]))
    {
        start++;
    }

    while (s1[end] && ft_strchr(set, s1[end]))
    {
        end--;
    }

    chrt = ft_substr(s1, start, end - start + 1);//plus 1 to add space for the zero terminaror 
    return (chrt);

}

//strmapi
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{   //char (*f)(unsigned int, char) refers to that f is a pointer to function that takes parameter from type
    //unsigned int and char and returns char 

    char *new; //pointer to char represent the memori alocation of the new str
    size_t len; //size of s
    size_t i;
    
    len = ft_strlen(s);
    i = 0;//loop incounter starts from 0

    if (!s)
        return (ft_strdup(""));

    new = malloc(sizeof(char) * len + 1);

    if (!new)
        return (NULL);

    while (i < len)
    {
        new[i] = (*f)(i,s[i]);
        i++;
    }

    new[i] = '\0';
    return (new);
}

//striteri
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int i;
    
    i = 0;

    if (!s)
        return ;

    while (s[i] != '\0')
    {
        (*f)(i,(s + i));
        i++;
    }
}

//itoi
static int get_size(int n)
{
    int size;

    size = 0;
    if(n <= 0)
        size ++;

    while (n != 0)
    {
        n = n / 10;
        size++;
    }
    return size;
}

static void filling_res(int size, int pica, int n, char *res){
    //n  holds the integer whose digits are to be filled in the array
    //res  is the pointer to the char array in which the digits of the integer n will be stored

    while(size > pica){
        res[size - 1] = n % 10 + '0';
        n = n / 10;
        size--;
    }
}

char    *ft_itoa(int n)
{
    int pica;
    int size;
    char *res;
    
    pica = 0;
    size = (get_size(n));
    res = (char *)malloc(size +1);

    if (!res)
        return (0);
    
    if (n == -2147483648)
    {
        res[0] = '-';
        res[1] = '2';
        n = 147483648;
        pica = 2;
    }

    if (n < 0)
    {
        res[0] = '-';
		pica = 1;
		n = -n;
    }
    filling_res(size,pica,n,res);
    res[size] = '\0';
    return (res);
}

//split
static void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab1;
	char const	*tmp;

	tmp = s;
	tab1 = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab1 = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab1;
		}
	}
	*tab1 = NULL;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}