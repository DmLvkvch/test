package com.dins.phonebook.exception;

public class NoteNotFoundException extends RuntimeException {
    public NoteNotFoundException(Long id) {
        super("Could not find note ".concat(String.valueOf(id)));
    }
}