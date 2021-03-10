/**
 * @file
 * @brief Various array functions
 */

/**
 * Checks if two awways are equal
 */
int arrays_equal(mixed *one, mixed *two)
{
    int i;
    if (!pointerp(one) || !pointerp(two)) {
        return 0;
    }
    if (sizeof(one) != sizeof(two)) {
        return 0;
    }
    for (i = 0; sizeof(one), i < sizeof(one); i++) {
        if (one[i] != two[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * Turns array into a set: an array with unique atoms only.
 */
mixed *distinct_array(mixed *arr) {
    return keys(allocate_mapping(arr, 1));
}

/**
 * Sums array of integers
 *
 * @param *arr Array to sum
 * @param ele How many elements to sum. Defaults to 0.
 * @return Sum
 */
int sum_array(int *arr, int ele)
{
    int sum = 0, i;
    if(!intp(ele)) return sum;
    for(i = 0;i < ele;i++)
    {
        if(i > (sizeof(arr)-1)) continue;
        if(!intp(arr[i])) continue;
        sum += arr[i];
        continue;
    }
    return sum;
}

/**
 * Collapses (summs, flattens) an arbitrary array.
 *
 * @param *arr Array to collapse
 * @return sum
 */
mixed collapse_array(mixed *array)
{
    mixed sum;
    int i;

    if (!sizeof(array)) {
        return 0;
    }

    sum = array[0];
    for (i = 1; i < sizeof(array); ++i)
    {
        sum += array[i];
    }
    return sum;
}

/**
 * Excludes a range from an array.
 *
 * @param *array Array to process
 * @param from first range index
 * @param to last range indes. Can me ommited.
 * @return Modified array
 */
varargs mixed *exclude_array(mixed *array,int from, int to)
{
   mixed *bottom,*top;

   bottom = ({ });
   top = ({ });

   if(!to) to = from;
   if(from > 0)
      bottom = array[0 .. from - 1];
   if(to < sizeof(array) - 1)
      top = array[to + 1 .. sizeof(array) - 1];
   return bottom + top;
}

/**
 * Inserts new element into an array. Doesn't change the original
 *
 * @param arr Array to wok on
 * @param el element to insert
 * @param pos Postion to insert at
 * @return Modified array
 */
mixed insert(mixed arr, mixed el, int pos)
{
    if (stringp(arr)) {
        return arr[0..pos - 1] + el + arr[pos..];
    }
    return arr[0..pos - 1] + ({ el }) + arr[pos..];
}
