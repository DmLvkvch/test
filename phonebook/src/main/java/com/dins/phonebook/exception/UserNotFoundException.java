package com.dins.phonebook.exception;

public class UserNotFoundException extends RuntimeException {
    public UserNotFoundException(Long id) {
        super("Could not find user ".concat(String.valueOf(id)));
    }
}