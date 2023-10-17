#include "main.h"

/**
 * make_fullpath - Construct the full path to the cmd.
 *
 * @cmd: The cmd to execute.
 * @pathcpy: A copy of the PATH environment variable.
 * @fullpath: The buffer to store the full path.
 * @fullpath_len: Pointer to the full path length.
 *
 * Return: 0 on success, -1 on failure.
 */
int make_fullpath(char *cmd, char *pathcpy, char *fullpath, int *fullpath_len)
{
	char *dir = strtok(pathcpy, ":");

	while (dir != NULL)
	{
		int dir_length = _strlen(dir);
		int cmd_length = _strlen(cmd);

		if (*fullpath_len + dir_length + cmd_length + 1 >= MAX_PATH_LENGTH)
		{
			perror("Path length exceeds the maximum path length");
			return (-1);
		}

		_memcpy(fullpath + *fullpath_len, dir, dir_length);
		*fullpath_len += dir_length;

		fullpath[*fullpath_len] = '/';
		(*fullpath_len)++;

		_memcpy(fullpath + *fullpath_len, cmd, cmd_length);
		*fullpath_len += cmd_length;

		fullpath[*fullpath_len] = '\0';

		if (access(fullpath, X_OK) == 0)
		{
			return (0); /*Full path constructed successfully*/
		}
		dir = strtok(NULL, ":");
		*fullpath_len = 0;  /* Reset the length for the next iteration */
	}

	return (-1); /*cmd not found*/
}


/**
 * cmd_exists - Check if a cmd exists in the PATH.
 *
 * @cmd: The cmd to check for.
 *
 * Return: 1 if the cmd exists, 0 otherwise.
 */
int cmd_exists(const char *cmd)
{
	/* Retrieve the PATH environment variable */
	const char *path_env = _getenv("PATH");
	char *path_env_copy;
	char *path;
	char fullpath[MAX_PATH_LENGTH];

	if (path_env == NULL)
	{
		return (0); /* PATH is not set, the cmd cannot exist */
	}
	path_env_copy = _strdup(path_env); /* Create a copy of path_env */
	if (path_env_copy == NULL)
	{
		perror("strdup");
		return (0);
	}

	path = strtok(path_env_copy, ":");
	while (path != NULL)
	{
		int path_length = _strlen(path);
		int cmd_length = _strlen(cmd);

		if (path_length + cmd_length + 2 < MAX_PATH_LENGTH)
		{
			fullpath[0] = '\0';
			_strncat(fullpath, path, path_length);
			_strncat(fullpath, "/", 1);
			_strncat(fullpath, cmd, cmd_length);

			if (access(fullpath, X_OK) == 0)
			{
				free(path_env_copy); /* Free the allocated memory */
				return (1); /* cmd exists in this directory */
			}
		}
		path = strtok(NULL, ":");
	}
	free(path_env_copy); /* Free the allocated memory */
	return (0); /* cmd not found in any directory in PATH */
}
