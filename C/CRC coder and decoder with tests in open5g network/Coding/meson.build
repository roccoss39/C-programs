libcoding_sources = files('crc16_ccitt.c', 'encoder.c', 'decoder.c')

libcoding = static_library('libcoding',
    sources : libcoding_sources,
    include_directories : include_directories('.'),
    c_args : ['-std=c99'],  # Wymuszamy użycie standardu C99
    install : false
)

# Instalacja nagłówków
install_headers('crc16_ccitt.h', 'encoder.h', 'decoder.h', subdir: 'coding')
