//ft_strlen 외부함수를 사용하기 위한 조치 취할 것!!

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t dst_len;
	size_t src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (!len)
		return (src_len);
	if (len <= dst_len)
		return (src_len + len);
	while (i < (len - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
