#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

char *concat(const char *s1, ...)
{
	va_list args;
	const char *s;
	char *p, *result;
	unsigned long l, m, n;

	m = n = strlen(s1);
	va_start(args, s1);
	while ((s = va_arg(args, char *))) {
			l = strlen(s);
			if ((m += l) < l) break;
		}
	va_end(args);
	if (s || m >= INT_MAX) return NULL;

	result = (char *)malloc(m + 1);
	if (!result) return NULL;

	memcpy(p = result, s1, n);
	p += n;
	va_start(args, s1);
	while ((s = va_arg(args, char *))) {
			l = strlen(s);
			if ((n += l) < l || n > m) break;
			memcpy(p, s, l);
			p += l;
		}
	va_end(args);
	if (s || m != n || p != result + n) {
			free(result);
			return NULL;
		}

	*p = 0;
	return result;
}
