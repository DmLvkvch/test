package com.dins.phonebook.exception;

public class DuplicatePhoneNumber extends RuntimeException{
    public DuplicatePhoneNumber(String number){
        super(String.format("Phone number %s already exists", number));
    }
}
