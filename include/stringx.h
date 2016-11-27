/*
	http-client-c 
	Copyright (C) 2012-2013  Swen Kooij
	
	This file is part of http-client-c.

    http-client-c is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    http-client-c is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with http-client-c. If not, see <http://www.gnu.org/licenses/>.

	Warning:
	This library does not tend to work that stable nor does it fully implent the
	standards described by IETF. For more information on the precise implentation of the
	Hyper Text Transfer Protocol:
	
	http://www.ietf.org/rfc/rfc2616.txt
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
	#include <locale>
#endif

/*
	Gets the offset of one string in another string
*/
int str_index_of(const char *a, char *b);

/*
	Checks if one string contains another string
*/
int str_contains(const char *haystack, const char *needle);


/*
	Removes last character from string
*/
char* trim_end(char *string, char to_trim);


/*
	Concecates two strings, a wrapper for strcat from string.h, handles the resizing and copying
*/
char* str_cat(char *a, char *b);


/*
	Converts an integer value to its hex character
*/
char to_hex(char code);

/*
	URL encodes a string
*/
char *urlencode(char *str);


/*
	Replacement for the string.h strndup, fixes a bug
*/
char *str_ndup (const char *str, size_t max);

/*
	Replacement for the string.h strdup, fixes a bug
*/
char *str_dup(const char *src);

/*
 	Search and replace a string with another string , in a string
*/
char *str_replace(char *search , char *replace , char *subject);


/*
	Get's all characters until '*until' has been found
*/
char* get_until(char *haystack, char *until);


/* decodeblock - decode 4 '6-bit' characters into 3 8-bit binary bytes */
void decodeblock(unsigned char in[], char *clrstr);

/*
	Decodes a Base64 string
*/
char* base64_decode(char *b64src);


/* encodeblock - encode 3 8-bit binary bytes as 4 '6-bit' characters */
void encodeblock( unsigned char in[], char b64str[], int len );

/*
	Encodes a string with Base64
*/
char* base64_encode(char *clrstr);
