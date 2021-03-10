/**
 * Outputs (to the screen) last tail_bytes of the file.
 *
 * @param file File to read.
 * @param tail_bytes How many bytes to you want to see
 */
varargs int tail(string file, int tail_bytes)
{
    string str;
    int diff;

    if (!tail_bytes) {
        tail_bytes = 2048;
    }

    diff = file_size(file);
    if (diff < 0) {
        return 0;
    }

    diff -= tail_bytes;
    if (diff < 0) {
        diff = 0;
    }
    str = read_bytes(file, diff, tail_bytes);
    if (!str) {
        return 0;
    }
    if (diff) {
        str = str[strsrch(str, "\n") + 1..];
    }

    write(str);

    return 1;
}
