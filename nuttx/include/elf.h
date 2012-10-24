/****************************************************************************
 * include/elf.h
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Reference: System V Application Binary Interface, Edition 4.1, March 18,
 * 1997, The Santa Cruz Operation, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __INCLUDE_ELF_H
#define __INCLUDE_ELF_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Values for Elf32_Ehdr::e_type */

#define ET_NONE           0       /* No file type */
#define ET_REL            1       /* Relocatable file */
#define ET_EXEC           2       /* Executable file */
#define ET_DYN            3       /* Shared object file */
#define ET_CORE           4       /* Core file */
#define ET_LOPROC         0xff00  /* Processor-specific */
#define ET_HIPROC         0xffff  /* Processor-specific */

/* Values for Elf32_Ehdr::e_machine */

#define EM_NONE            0      /* No machine */
#define EM_M32             1      /* AT&T WE 32100 */
#define EM_SPARC           2      /* SPARC */
#define EM_386             3      /* Intel 80386 */
#define EM_68K             4      /* Motorola 68000 */
#define EM_88K             5      /* Motorola 88000 */
#define EM_860             7      /* Intel 80860 */
#define EM_MIPS            8      /* MIPS RS3000 Big-Endian */
#define EM_MIPS_RS4_BE     10     /* MIPS RS4000 Big-Endian */
                                  /* 11-16 Reserved for future use */

/* Values for Elf32_Ehdr::e_version */

#define EV_NONE            0      /* Invalid version */
#define EV_CURRENT         1      /* The current version */

/* Ehe ELF identifier */

#define EI_MAG0            0      /* File identification */
#define EI_MAG1            1      /* "  " "            " */
#define EI_MAG2            2      /* "  " "            " */
#define EI_MAG3            3      /* "  " "            " */
#define EI_CLASS           4      /* File class */
#define EI_DATA            5      /* Data encoding */
#define EI_VERSION         6      /* File version */
#define EI_PAD             7      /* Start of padding bytes */
#define EI_NIDENT          16     /* Size of eident[] */

#define EI_MAGIC_SIZE      4
#define EI_MAGIC           {0x7f, 'E', 'L', 'F'}

/* Values for EI_CLASS */

#define ELFCLASSNONE       0      /* Invalid class */
#define ELFCLASS32         1      /* 32-bit objects */
#define ELFCLASS64         2      /* 64-bit objects */

/* Values for EI_DATA */

#define ELFDATANONE        0     /* Invalid data encoding */
#define ELFDATA2LSB        1     /* Least significant byte occupying the lowest address */
#define ELFDATA2MSB        2     /* Most significant byte occupying the lowest address */

/* Figure 4-7: Special Section Indexes */

#define SHN_UNDEF          0
#define SHN_LORESERVE      0xff00
#define SHN_LOPROC         0xff00
#define SHN_HIPROC         0xff1f
#define SHN_ABS            0xfff1
#define SHN_COMMON         0xfff2
#define SHN_HIRESERVE      0xffff

/* Figure 4-9: Section Types, sh_type */

#define SHT_NULL           0
#define SHT_PROGBITS       1
#define SHT_SYMTAB         2
#define SHT_STRTAB         3
#define SHT_RELA           4
#define SHT_HASH           5
#define SHT_DYNAMIC        6
#define SHT_NOTE           7
#define SHT_NOBITS         8
#define SHT_REL            9
#define SHT_SHLIB          10
#define SHT_DYNSYM         11
#define SHT_LOPROC         0x70000000
#define SHT_HIPROC         0x7fffffff
#define SHT_LOUSER         0x80000000
#define SHT_HIUSER         0xffffffff

/* Figure 4-11: Section Attribute Flags, sh_flags */

#define SHF_WRITE          1
#define SHF_ALLOC          2
#define SHF_EXECINSTR      4
#define SHF_MASKPROC       0xf0000000

/* Definitions for Elf32_Sym::st_info */

#define ELF32_ST_BIND(i)   ((i)>>4)
#define ELF32_ST_TYPE(i)   ((i)&0xf)
#define ELF32_ST_INFO(b,t) (((b)<<4)+((t)&0xf))

/* Figure 4-16: Symbol Binding, ELF32_ST_BIND */

#define STB_LOCAL          0
#define STB_GLOBAL         1
#define STB_WEAK           2
#define STB_LOPROC         13
#define STB_HIPROC         15

/* Figure 4-17: Symbol Types, ELF32_ST_TYPE */

#define STT_NOTYPE         0
#define STT_OBJECT         1
#define STT_FUNC           2
#define STT_SECTION        3
#define STT_FILE           4
#define STT_LOPROC         13
#define STT_HIPROC         15

/* Definitions for Elf32_Rel*::r_info */

#define ELF32_R_SYM(i)    ((i)>>8)
#define ELF32_R_TYPE(i)   ((unsigned char)(i))
#define ELF32_R_INFO(s,t) (((s)<<8)+(unsigned char)(t))

/* Figure 5-2: Segment Types, p_type */

#define PT_NULL            0
#define PT_LOAD            1
#define PT_DYNAMIC         2
#define PT_INTERP          3
#define PT_NOTE            4
#define PT_SHLIB           5
#define PT_PHDR            6
#define PT_LOPROC          0x70000000
#define PT_HIPROC          0x7fffffff

/* Figure 5-3: Segment Flag Bits, p_flags */

#define PF_X               1          /* Execute */
#define PF_W               2          /* Write */
#define PF_R               4          /* Read */
#define PF_MASKPROC        0xf0000000 /* Unspecified */

/* Figure 5-10: Dynamic Array Tags, d_tag */

#define DT_NULL            0          /* d_un=ignored */
#define DT_NEEDED          1          /* d_un=d_val */
#define DT_PLTRELSZ        2          /* d_un=d_val */
#define DT_PLTGOT          3          /* d_un=d_ptr */
#define DT_HASH            4          /* d_un=d_ptr */
#define DT_STRTAB          5          /* d_un=d_ptr */
#define DT_SYMTAB          6          /* d_un=d_ptr */
#define DT_RELA            7          /* d_un=d_ptr */
#define DT_RELASZ          8          /* d_un=d_val */
#define DT_RELAENT         9          /* d_un=d_val */
#define DT_STRSZ           10         /* d_un=d_val */
#define DT_SYMENT          11         /* d_un=d_val */
#define DT_INIT            12         /* d_un=d_ptr */
#define DT_FINI            13         /* d_un=d_ptr */
#define DT_SONAME          14         /* d_un=d_val */
#define DT_RPATH           15         /* d_un=d_val */
#define DT_SYMBOLIC        16         /* d_un=ignored */
#define DT_REL             17         /* d_un=d_ptr */
#define DT_RELSZ           18         /* d_un=d_val */
#define DT_RELENT          19         /* d_un=d_val */
#define DT_PLTREL          20         /* d_un=d_val */
#define DT_DEBUG           21         /* d_un=d_ptr */
#define DT_TEXTREL         22         /* d_un=ignored */
#define DT_JMPREL          23         /* d_un=d_ptr */
#define DT_BINDNOW         24         /* d_un=ignored */
#define DT_LOPROC          0x70000000 /* d_un=unspecified */
#define DT_HIPROC          0x7fffffff /* d_un= unspecified */

/****************************************************************************
 * Public Type Definitions
 ****************************************************************************/

/* Figure 4.2: 32-Bit Data Types */

typedef uint32_t  ELF32_Addr  /* Unsigned program address */
typedef uint16_t  ELF32_Half  /* Unsigned medium integer */
typedef uint32_t  ELF32_Off   /* Unsigned file offset */
typedef int32_t   ELF32_Sword /* Signed large integer */
typedef uint32_t  ELF32_Word  /* Unsigned large integer */

/* Figure 4-3: ELF Header */

typedef struct
{
  unsigned char e_ident[EI_NIDENT];
  ELF32_Half    e_type;
  ELF32_Half    e_machine;
  ELF32_Word    e_version;
  ELF32_Addr    e_entry;
  ELF32_Off     e_phoff;
  ELF32_Off     e_shoff;
  ELF32_Word    e_flags;
  ELF32_Half    e_ehsize;
  ELF32_Half    e_phentsize;
  ELF32_Half    e_phnum;
  ELF32_Half    e_shentsize;
  ELF32_Half    e_shnum;
  ELF32_Half    e_shstrndx;
} Elf32_Ehdr;

/* Figure 4-8: Section Header */

typedef struct
{
  ELF32_Word    sh_name;
  ELF32_Word    sh_type;
  ELF32_Word    sh_flags;
  ELF32_Addr    sh_addr;
  ELF32_Off     sh_offset;
  ELF32_Word    sh_size;
  ELF32_Word    sh_link;
  ELF32_Word    sh_info;
  ELF32_Word    sh_addralign;
  ELF32_Word    sh_entsize;
} Elf32_Shdr;

/* Figure 4-15: Symbol Table Entry */

typedef struct
{
  ELF32_Word    st_name;
  ELF32_Addr    st_value;
  ELF32_Word    st_size;
  unsigned char st_info;
  unsigned char st_other;
  ELF32_Half    st_shndx;
} Elf32_Sym;

/* Figure 4-19: Relocation Entries */

typedef struct
{
  ELF32_Addr   r_offset;
  ELF32_Word   r_info;
} Elf32_Rel;

typedef struct
{
  ELF32_Addr   r_offset;
  ELF32_Word   r_info;
  ELF32_Sword  r_addend;
} Elf32_Rela;

/* Figure 5-1: Program Header */

typedef struct
{
  Elf32_Word   p_type;
  Elf32_Off    p_offset;
  Elf32_Addr   p_vaddr;
  Elf32_Addr   p_paddr;
  Elf32_Word   p_filesz;
  Elf32_Word   p_memsz;
  Elf32_Word   p_flags;
  Elf32_Word   p_align;
} Elf32_Phdr;

/* Figure 5-9: Dynamic Structure */

typedef struct
{
  Elf32_Sword  d_tag;
  union
  {
    Elf32_Word d_val;
    Elf32_Addr d_ptr;
  } d_un;
} Elf32_Dyn;

//extern Elf32_Dyn _DYNAMIC[] ;

#endif /* __INCLUDE_ELF_H */
