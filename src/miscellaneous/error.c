/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:45:38 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/01 14:45:39 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
**	Real OpenSSL has 4 columns, each 18 chars wide.
**	In OpenSSL the columns ARE fixed, unlike in ls.
*/
#define COLS 4
#define COL_WIDTH 18
#define INDENT "    "

const char*	g_message_digest_commands[] = {
	"md5",
	"sha1",
	"sha256",
	"sha224",
	"sha512",
	"sha384",
	(NULL)
};

const char*	g_cipher_flags[] = {
	"-d\tDecrypt mode [default: encrypt]",
	"-i\tInput file to read from [default: stdin]",
	"-o\tOutput file to write to [default: stdout]",
	"-p\tPassword to use (string)",
	"-s\tSalt to use (hexidecimal string)",
	"-k\tKey to use (hexidecimal string)",
	"-v\tInitialization vector to use (hexidecimal string)",
	(NULL)
};

const char*	g_cipher_commands[] = {
	"base64",
	"des",
	"des-ecb",
	"des-cbc",
	(NULL)
};

const char*	g_message_digest_flags[] = {
	"-s\tPrint the sum of the given string",
	(NULL)
};


/*
**	Prints string in a null-terminated list in indented columns.
**	Items go top-to-bottom and then left-to-right.
*/

static void	print_cols(const char* table[], int cols)
{
	int	rows;
	int	n;

	n = 0;
	while (table[n])
		n++;
	rows = (n / cols) + ((n % cols != 0) ? 1 : 0);
	for (int i = 0; i < rows; i++)
	{
		ft_dprintf(STDERR_FILENO, INDENT);
		for (int j = 0; j < cols; ++j)
		{
			if (!table[i + (j * rows)])
				break;
			ft_dprintf(STDERR_FILENO, "%-*s", COL_WIDTH,
					table[i + (j * rows)]);
		}
		ft_dprintf(STDERR_FILENO, "\n");
	}
}

static void	print_menu(void)
{
	ft_dprintf(STDERR_FILENO, "\nMessage Digest:\n");
	print_cols(g_message_digest_commands, COLS);
	ft_dprintf(STDERR_FILENO, "\n");
	print_cols(g_message_digest_flags, 1);

	ft_dprintf(STDERR_FILENO, "\nCipher:\n");
	print_cols(g_cipher_commands, COLS);
	ft_dprintf(STDERR_FILENO, "\n");
	print_cols(g_cipher_flags, 1);
}

void	handle_error(int errorcode, char *str)
{
	ft_dprintf(STDERR_FILENO, "ft_ssl: error: ");
	if ((errorcode == error_command) || (errorcode == error_flag))
	{
		if (errorcode == error_command)
			ft_dprintf(STDERR_FILENO, "'%s' is an invalid command.\n", str);
		print_menu();
	}
	if (errorcode == error_file)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", str, strerror(errno));
	if (errorcode == error_incomplete)
		ft_dprintf(STDERR_FILENO, "You did not provide %s.\n", str);
	exit(1);
}