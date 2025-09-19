#ifndef ONEGIN_SORTER_H
#define ONEGIN_SORTER_H

/**
 * @brief Compare strings from start (ignoring punctuation/whitespace)
 * @param vpstr1 First pointer to ptr-wrap, containing ptr to string to compare
 * @param vpstr2 Second pointer to ptr-wrap, containing ptr to string to compare
 * @return Comparison result (-1, 0, 1)
 */
int my_strcmp_start(const void* vpstr1, const void* vpstr2);

/**
 * @brief Compare strings from end (reverse order) (ignoring punctuation/whitespace)
 * @param vpstr1 First pointer to ptr-wrap, containing ptr to string to compare
 * @param vpstr2 Second pointer to ptr-wrap, containing ptr to string to compare
 * @return Comparison result (-1, 0, 1)
 */
int my_strcmp_end(const void* vpstr1, const void* vpstr2);


#endif //ONEGIN_SORTER_H