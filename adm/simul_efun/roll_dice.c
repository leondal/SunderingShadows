/**
 * @file
 */

/**
 * Rolls a NdM dice
 *
 * @param num N
 * @param sides M
 * @reutn Sum of the roll
 */
int roll_dice(int num, int sides)
{
    int x, cnt;

    cnt = 0;
    for (x = 0; x < num; x++) {
        cnt += random(sides) + 1;
    }
    return cnt;
}
