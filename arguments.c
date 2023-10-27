#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Assume you have the ft_split function you provided earlier

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 0;
	num = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg++;
		i++;
	}
	// if (!(s[i] >= '0' && s[i] <= '9'))
	// 	return 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if (neg == 1)
		num *= -1;
	return (num);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	// char	*substr;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			// lst[i++] = substr;
			s += word_len;
		}
	}
	lst[i] = NULL;
	// free (substr);
	return (lst);
}

int	*argument(const char *s)
{
	int		i;
	char	**lst;
	int		*arr;

	lst = ft_split(&s[0], ' ');
	arr = (int *)malloc(500 * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (lst[i])
	{
		arr[i] = ft_atoi(lst[i]);
		if (arr[i] == 0)
		{
			free (arr);
			free (lst);
			return (0);
		}
		i++;
	}
	free (lst);
	return (arr);
}

// int	divided_argument(char *input)
// {
// 	char	c;
// 	int		i;
// 	char	*substr;
// 	char	**substr_array;
// 	bool	is_numeric;

// 	c = ' ';
// 	substr_array = ft_split(input, c);
// 	if (!substr_array)
// 		return (1);

// 	i = 0;
// 	while (substr_array[i])
// 	{
// 		substr = substr_array[i];
// 		i++;
// 	}
//     ft_atoi(substr);
// 	if (ft_atoi(substr) == 0 && substr[0] != '0')
// 		return (1);

// 	i = 0;
// 	while (substr_array[i])
// 	{
// 		free(substr_array[i]);
// 		i++;
// 	}
// 	free(substr_array);
// 	return (0);
// }
