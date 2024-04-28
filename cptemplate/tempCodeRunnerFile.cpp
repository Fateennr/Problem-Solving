bool search(string str, int len)
// {
//     int idx;
//     Node *current = root;
//     for(int i=0; i<len; i++)
//     {
//         idx = str[i] - 'a';
//         if(current->next[idx] == NULL)
//         {
//             return false;
//         }
//         else
//         {
//             current = current->next[idx];
//         }
//     }
//     return current->endmark;
// }