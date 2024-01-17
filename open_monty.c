#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * open - opens a file and returns a file descriptor
 * @filename: name of file to open
 * @flags:  specifying the mode in which to open the file.
 * @mode: permissions
 *
 * Return: file descriptor on success, -1 on failure.
 */

int open(const char *filename, int flags[, mode_t mode])
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		perror("open failed");
	}
	return (fd);
}
