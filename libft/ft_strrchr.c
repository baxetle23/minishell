char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	if (s[0] == '\0' && c != '\0')
		return (0);
	p = 0;
	while (*s != '\0')
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	if (c == '\0')
		p = (char *)s;
	return (p);
}
