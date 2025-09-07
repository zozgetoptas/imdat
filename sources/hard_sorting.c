#include "../includes/push_swap.h"
#include <stdlib.h>

// Normalization fonksiyonu ekle
void normalize_stack(t_stack **stack)
{
    if (!stack || !*stack || !(*stack)->top)
        return;
        
    int size = (*stack)->size;
    int *values = malloc(sizeof(int) * size);
    int *sorted = malloc(sizeof(int) * size);
    t_node *current = (*stack)->top;
    int i = 0;
    
    // Değerleri array'e al
    while (current && i < size)
    {
        values[i] = current->value;
        sorted[i] = current->value;
        current = current->next;
        i++;
    }
    
    // Sorted array'i sırala (bubble sort - küçük array için)
    for (i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1]; 
                sorted[j + 1] = temp;
            }
        }
    }
    
    // Stack'teki değerleri normalize et
    current = (*stack)->top;
    while (current)
    {
        // Bu değerin sıralamadaki pozisyonunu bul
        for (i = 0; i < size; i++)
        {
            if (current->value == sorted[i])
            {
                current->value = i; // 0,1,2,3... şeklinde normalize et
                break;
            }
        }
        current = current->next;
    }
    
    free(values);
    free(sorted);
}
int get_max_bits(t_stack *a)
{
    if (!a || !a->top)
        return 0;
        
    // Normalize edilmiş sayılarda max değer stack size - 1 olur
    int max_value = a->size - 1;
    int max_bit_count = 0;
    
    if (max_value == 0)
        return 1;
        
    while ((max_value >> max_bit_count) != 0)
        max_bit_count++;
        
    return max_bit_count;
}

void radix_sort(t_stack **a, t_stack **b)
{
    // Önce normalize et
    normalize_stack(a);
    
    int max_bit_count = get_max_bits(*a);
    int i = 0;
    
    while (i < max_bit_count)
    {
        int a_stack_size = (*a)->size;
        int j = 0;
        
        while (j < a_stack_size)
        {
            int value = (*a)->top->value;
            
            // Bit kontrolü - 0 ise B'ye gönder, 1 ise A'da döndür
            if (((value >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        
        // B'deki tüm elemanları geri al
        while ((*b)->size > 0)
            pa(a, b);
            
        i++;
    }
}
