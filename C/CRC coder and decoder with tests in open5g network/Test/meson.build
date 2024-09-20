

testunit_unit_sources = files('''
    abts-main.c
    proto-message-test.c
    s1ap-message-test.c
    nas-message-test.c
    gtp-message-test.c
    ngap-message-test.c
    sbi-message-test.c
    security-test.c
    crash-test.c
    crc16-test.c
'''.split())

libinc = include_directories('../../lib/coding')

testunit_unit_exe = executable('unit',
    sources : testunit_unit_sources,
    c_args : [testunit_core_cc_flags, sbi_cc_flags],
    include_directories : libinc,  # Definiuje ścieżki do plików nagłówkowych
    dependencies : [libs1ap_dep,
                    libgtp_dep,
                    libngap_dep,
                    libnas_eps_dep,
                    libsbi_dep],
    link_with : libcoding 
)


test('unit', testunit_unit_exe, is_parallel: false, suite: 'unit')
