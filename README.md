# ojcat

**A lightweight ELF binary inspection tool built from scratch in C.**

`ojcat` is a low-level command-line utility for inspecting ELF binaries and viewing their internal structure in several representations.

The project is currently Linux-oriented and is designed with portability and support for additional operating systems as a future direction.

---

# English

## About

`ojcat` is a lightweight command-line tool for inspecting ELF binaries.

It can read and display information from an ELF file, including its header and program headers, and can represent the file contents as hexadecimal, binary, or ASCII data.

The project is written in C and built around direct interaction with binary data and file structures.

The goal is to keep the tool small, transparent, and close to the underlying data instead of hiding the process behind high-level abstractions.

---

## Why ojcat?

`ojcat` exists for several reasons.

One of them is educational: understanding how executable files are structured by working directly with their bytes and data structures.

Another is practical: building a small utility that can inspect binaries from the command line without depending on a large framework.

There are also other reasons behind the project that are intentionally left unexplained for now.

---

## Features

* ELF header inspection
* ELF program header inspection
* Hexadecimal file representation
* Binary file representation
* ASCII file representation
* Command-line interface
* Direct binary file reading
* Written in C
* Lightweight and dependency-free at runtime
* Designed for low-level inspection and experimentation

---

## Usage

```text
Usage: ojcat <command> <file>

Commands:
-h              Print the ELF header information
-s              Print program headers
-x              Print the file as hex
-b              Print the file as binary
-a              Print the file as ASCII (with hex-like layout)

Example:
ojcat -h myfile.elf
```

---

## Examples

Inspect an ELF header:

```bash
ojcat -h /bin/ls
```

Inspect program headers:

```bash
ojcat -s /bin/ls
```

Display a file as hexadecimal:

```bash
ojcat -x file
```

Display a file as binary:

```bash
ojcat -b file
```

Display a file as ASCII:

```bash
ojcat -a file
```

---

## Build

The project can be built directly with the included `Makefile`.

```bash
make
```

This produces the `ojcat` executable.

---

## Project Structure

```text
ojcat/
├── include/
│   ├── args.h
│   ├── ascii_dump.h
│   ├── bindump.h
│   ├── elf_header.h
│   ├── elf_reader.h
│   ├── elf_sections.h
│   ├── elf_types.h
│   ├── file.h
│   ├── hexdump.h
│   └── output.h
├── src/
│   ├── args.c
│   ├── ascii_dump.c
│   ├── bindump.c
│   ├── elf_header.c
│   ├── elf_reader.c
│   ├── elf_sections.c
│   ├── elf_types.c
│   ├── file.c
│   ├── hexdump.c
│   ├── main.c
│   └── output.c
├── Makefile
```

The source is separated into components responsible for argument parsing, ELF structures, file handling, output formatting, and different binary representations.

---

## Technical Direction

`ojcat` currently focuses on ELF binaries and Linux environments.

The project is intentionally kept close to the binary format itself. Instead of relying on external ELF-parsing frameworks, the implementation works directly with file data and ELF structures.

Future development may expand the project toward broader portability and support for additional operating systems and executable formats.

---

## Roadmap

Possible future directions include:

* Better ELF structure parsing
* More complete program header support
* Improved recognition of ELF types
* More detailed section information
* Better error handling
* More portable file handling
* Support for additional operating systems
* Support for additional executable formats
* Improved command-line interface
* More inspection and analysis capabilities

The roadmap is intentionally open-ended.

---

## Philosophy

`ojcat` is built around a simple idea:

**Understand the data by working with the data itself.**

The project is not intended to hide the structure of a binary behind layers of abstraction.

It is meant to provide a small and understandable interface for examining what is actually inside an executable file.

---

## Version

Current release:

```text
v1.0
```

---

## Part of OJ

`ojcat` is part of the broader OJ project, which focuses on building low-level systems, developer utilities, security tools, and software from scratch.

---

## License

This project is open source and distributed under its chosen license.

---

# العربية

## عن المشروع

`ojcat` هي أداة خفيفة تعمل من سطر الأوامر لفحص ملفات ELF التنفيذية.

يمكنها قراءة وعرض المعلومات الموجودة داخل ملف ELF، بما في ذلك الـheader والـprogram headers، بالإضافة إلى إمكانية عرض محتوى الملف بصيغ hexadecimal أو binary أو ASCII.

المشروع مكتوب بلغة C، ومبني حول التعامل المباشر مع البيانات الثنائية وهياكل الملفات.

الهدف هو إبقاء الأداة صغيرة وواضحة وقريبة من البيانات الأساسية، بدلًا من إخفاء طريقة العمل خلف طبقات عالية المستوى من التجريد.

---

## لماذا ojcat؟

تم إنشاء `ojcat` لعدة أسباب.

أحد هذه الأسباب تعليمي، وهو فهم كيفية بناء وتنظيم الملفات التنفيذية من خلال التعامل المباشر مع الـbytes وهياكل البيانات الخاصة بها.

وهناك سبب عملي أيضًا، وهو بناء أداة صغيرة يمكن استخدامها من سطر الأوامر لفحص الملفات الثنائية دون الاعتماد على framework كبير.

وهناك أسباب أخرى وراء المشروع، ولكن تم تركها عمدًا دون تفسير في الوقت الحالي.

---

## المميزات

* فحص ELF header
* فحص ELF program headers
* عرض الملفات بصيغة hexadecimal
* عرض الملفات بصيغة binary
* عرض الملفات بصيغة ASCII
* واجهة تعمل من سطر الأوامر
* قراءة مباشرة للملفات الثنائية
* مكتوبة بلغة C
* خفيفة ولا تحتاج إلى dependencies أثناء التشغيل
* مصممة للفحص منخفض المستوى والتجربة

---

## الاستخدام

```text
Usage: ojcat <command> <file>

Commands:
-h              Print the ELF header information
-s              Print program headers
-x              Print the file as hex
-b              Print the file as binary
-a              Print the file as ASCII (with hex-like layout)

Example:
ojcat -h myfile.elf
```

---

## أمثلة

فحص ELF header:

```bash
ojcat -h /bin/ls
```

فحص program headers:

```bash
ojcat -s /bin/ls
```

عرض الملف بصيغة hexadecimal:

```bash
ojcat -x file
```

عرض الملف بصيغة binary:

```bash
ojcat -b file
```

عرض الملف بصيغة ASCII:

```bash
ojcat -a file
```

---

## البناء

يمكن بناء المشروع مباشرة باستخدام ملف `Makefile` الموجود معه.

```bash
make
```

سيؤدي ذلك إلى إنشاء الملف التنفيذي `ojcat`.

---

## هيكل المشروع

```text
ojcat/
├── include/
│   ├── args.h
│   ├── ascii_dump.h
│   ├── bindump.h
│   ├── elf_header.h
│   ├── elf_reader.h
│   ├── elf_sections.h
│   ├── elf_types.h
│   ├── file.h
│   ├── hexdump.h
│   └── output.h
├── src/
│   ├── args.c
│   ├── ascii_dump.c
│   ├── bindump.c
│   ├── elf_header.c
│   ├── elf_reader.c
│   ├── elf_sections.c
│   ├── elf_types.c
│   ├── file.c
│   ├── hexdump.c
│   ├── main.c
│   └── output.c
├── Makefile
```

تم تقسيم المصدر إلى مكونات مسؤولة عن تحليل الـarguments، وهياكل ELF، والتعامل مع الملفات، وتنسيق الإخراج، والتمثيلات المختلفة للبيانات الثنائية.

---

## الاتجاه التقني

يركز `ojcat` حاليًا على ملفات ELF وبيئات Linux.

تم تصميم المشروع ليكون قريبًا من صيغة الملف الثنائية نفسها. وبدلًا من الاعتماد على frameworks خارجية لتحليل ELF، يتعامل التنفيذ مباشرة مع بيانات الملف وهياكل ELF.

يمكن أن يتجه التطوير مستقبلًا نحو قابلية نقل أوسع ودعم أنظمة تشغيل إضافية وصيغ ملفات تنفيذية أخرى.

---

## خارطة الطريق

تشمل الاتجاهات المستقبلية المحتملة:

* تحسين تحليل هياكل ELF
* دعم أكثر اكتمالًا للـprogram headers
* تحسين التعرف على أنواع ELF
* توفير معلومات أكثر تفصيلًا عن الـsections
* تحسين التعامل مع الأخطاء
* جعل التعامل مع الملفات أكثر قابلية للنقل
* دعم أنظمة تشغيل إضافية
* دعم صيغ ملفات تنفيذية إضافية
* تحسين واجهة سطر الأوامر
* إضافة قدرات أكبر للفحص والتحليل

خارطة الطريق مفتوحة عمدًا ويمكن أن تتغير مع تطور المشروع.

---

## فلسفة المشروع

يعتمد `ojcat` على فكرة بسيطة:

**افهم البيانات من خلال التعامل مع البيانات نفسها.**

المشروع لا يهدف إلى إخفاء بنية الملف الثنائي خلف طبقات من التجريد.

بل يهدف إلى توفير واجهة صغيرة ومفهومة لفحص ما يوجد فعليًا داخل الملف التنفيذي.

---

## الإصدار

الإصدار الحالي:

```text
v1.0
```

---

## جزء من OJ

`ojcat` هو جزء من مشروع OJ الأكبر، والذي يركز على بناء الأنظمة منخفضة المستوى، وأدوات المطورين، وأدوات الأمن السيبراني، والبرمجيات من الصفر.

---

## الترخيص

هذا المشروع مفتوح المصدر ويتم توزيعه تحت الترخيص الذي اختاره المشروع.

