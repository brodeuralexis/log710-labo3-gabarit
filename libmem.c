#include "./libmem.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include <stdlib.h>

// IMPORTANT(Alexis Brodeur): Dans ce fichier, et tout code utilisé par ce fichier,
// vous ne pouvez pas utiliser `malloc`, `free`, etc.

static struct {
    void*           ptr;
    size_t          len;
    mem_strategy_t  strategy;
} state;

// IMPORTANT(Alexis Brodeur): Avant de commencer à implémenter le code de ce
// laboratoire, discuter en équipe afin d'être sûr de tous avoir compris la
// structure de données.

typedef struct block {
    struct block*   previous;
    size_t          size;
    bool            free;
} block_t;

/**
 * @brief Retourne le premier bloc dans la liste de blocs.
 *
 * @return Le premier bloc
 */
static inline block_t* block_first()
{
    // IMPORTANT(Alexis Brodeur): Voici un indice !
    return state.ptr;
}

/**
 * @brief Retourne le prochain bloc dans la liste de blocks.
 * @note Retourne @e NULL s'il n'y a pas de prochain bloc.
 *
 * @param block Un bloc
 * @return Le prochain bloc
 */
static block_t* block_next(block_t* block)
{
    // TODO(Alexis Brodeur): À implémenter.

    ((void) block);

    // IMPORTANT(Alexis Brodeur):
    // À partir d'un noeud, comment trouver le début du prochain noeud ?
    //
    // Commend déterminer si vous avez atteint la fin de la liste de noeuds ?

    return NULL;
}

// NOTE(Alexis Brodeur): Si vous ne comprenez pas ces macros utilitaires, venez
// me voir.

/**
 * @brief Une macro permettant d'itérer sur tous les blocs.
 *
 * @code{C}
 * int size = 0;
 * FOR_EACH_BLOCK(block)
 * {
 *     size += block->size;
 * }
 * @endcode
 *
 * @param block Le nom du pointeur vers le bloc dans le corp de la boucle
 */
#define FOR_EACH_BLOCK(block) \
    for (block_t* block = block_first(); block != NULL; block = block_next(block))

/**
 * @brief Une macro permettant d'itérer sur tous les blocs.
 *
 * @param block Le nom du pointeur vers le bloc dans le corp de la boucle
 */
#define FOR_EACH_FREE_BLOCK(block) \
    FOR_EACH_BLOCK(block) if (block->free)

/**
 * @brief Une macro permettant d'itérer sur tous les blocs.
 *
 * @param block Le nom du pointeur vers le bloc dans le corp de la boucle
 */
#define FOR_EACH_USED_BLOCK(block) \
    FOR_EACH_BLOCK(block) if (!block->free)

/**
 * @brief Acquiert un nombre d'octet du bloc dans le cadre d'une allocation de
 * mémoire.
 *
 * @param block Le noeud libre à utiliser
 * @param size La taille de l'allocation
 */
static void block_acquire(block_t* block, size_t size)
{
    assert(block != NULL);
    assert(block->size >= size);
    assert(block->free);

    // TODO(Alexis Brodeur): À implémenter.
    //
    // IMPORTANT(Alexis Brodeur):
    // Que faire si `block->size > size` ?
}

/**
 * @brief Relâche la mémoire utilisé par une allocation, et fusionne le bloc
 * avec son précédant et suivant lorsque nécessaire.
 *
 * @param block Un bloc à relâcher
 */
static void block_release(block_t* block)
{
    assert(block != NULL);
    assert(!block->free);

    // TODO(Alexis Brodeur): À implémenter.

    // IMPORTANT(Alexis Brodeur):
    // Que faire si le bloc précédent est libre ?
    // Que faire si le bloc suivant est libre ?
}

void mem_init(size_t size, mem_strategy_t strategy)
{
    assert(size > 0);
    assert(strategy >= 0);
    assert(strategy < _NUM_MEM_STRATEGIES);

    // TODO(Alexis Brodeur): Initialiser l'allocation de mémoire.

    // IMPORTANT(Alexis Brodeur): Combien avec-vous de blocs initialement ?
}

void mem_deinit(void)
{
    // TODO(Alexis Brodeur): Libérez la mémoire utilisée par votre gestionnaire.
}

void* mem_alloc(size_t size)
{
    assert(size > 0);

    // TODO(Alexis Brodeur): Alloue un bloc de `size` octets.
    //
    // Ce bloc et ses métadonnées doivent être réservées dans la mémoire pointée
    // par `state.ptr`.

    // NOTE(Alexis Brodeur): Utiliser la structure `block_t` ci-dessus et les
    // ses fonctions associées.
    //
    // Venez me poser des questions si cela n'est pas clair !

    return NULL;
}

void mem_free(void* ptr)
{
    assert(ptr != NULL);

    // TODO(Alexis Brodeur): Libère le bloc de mémoire pointé par `ptr`.
    //
    // Assumez que `ptr` est TOUJOURS un pointeur retourné par `mem_alloc`.
}

size_t mem_get_free_block_count()
{
    // TODO(Alexis Brodeur): Indiquez combien de blocs de mémoire sont libre.

    return 0;
}

size_t mem_get_allocated_block_count()
{
    // TODO(Alexis Brodeur): Indiquez combien de blocs de mémoire sont alloués.

    return 0;
}

size_t mem_get_free_bytes()
{
    // TODO(Alexis Brodeur): Indiquez combien d'octets sont disponibles pour
    // des allocations de mémoire.

    return 0;
}

size_t mem_get_biggest_free_block_size()
{
    // TODO(Alexis Brodeur): Indiquez la taille en octets du plus gros plus de
    // mémoire libre.

    return 0;
}

size_t mem_count_small_free_blocks(size_t maxBytes)
{
    assert(maxBytes > 0);

    // TODO(Alexis Brodeur): Indiquez combien de blocs de mémoire plus petit que
    // `maxBytes` sont disponible.

    return 0;
}

bool mem_is_allocated(void* ptr)
{
    assert(ptr != NULL);

    // TODO(Alexis Brodeur): Indiquez si l'octet pointé par `ptr` est alloué.

    // NOTE(Alexis Brodeur): Ce pointeur peut pointer vers n'importe quelle
    // adresse mémoire.

    return false;
}

void mem_print_state(void)
{
    // TODO(Alexis Brodeur): Imprimez l'état de votre structure de données.

    // NOTE(Alexis Brodeur): Pensez à une représentation simple et facile à lire
    // pour ma santée mentale lors de la correction.
    //
    // Ex.:
    //
    // ```
    // A100 F24 A20 A58 F20 A27 F600
    // ```
}
