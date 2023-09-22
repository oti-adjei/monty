#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/* list_funcs1.c */
size_t dbllinkdlst_len(const dbllinkdlstt_r *h);
dbllinkdlstt_r *add_dnodeint(dbllinkdlstt_r **head, const int n);
size_t print_dbllinkdlst(const dbllinkdlstt_r *h);
int delete_dnodeint_at_index(dbllinkdlstt_r **head, unsigned int index);
dbllinkdlstt_r *get_dnodeint_at_index(dbllinkdlstt_r *head, unsigned int index);

/* list_funcs2.c */
dbllinkdlstt_r *insert_dnodeint_at_index(dbllinkdlstt_r **h, unsigned int idx, int n);
dbllinkdlstt_r *add_dnodeint_end(dbllinkdlstt_r **head, const int n);
void free_dbllinkdlst(dbllinkdlstt_r *head);

#endif
