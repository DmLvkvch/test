package com.dins.phonebook.service;

import com.dins.phonebook.domain.PhoneBookNote;
import org.springframework.hateoas.EntityModel;

import java.util.Optional;

public interface PhoneBookService {
    Optional<PhoneBookNote> getPhoneBookNoteById(Long id);
    Iterable<PhoneBookNote> getUserPhoneBook(Long id);
    EntityModel<PhoneBookNote> getPhoneBookNoteByUserIdAndId(Long id, Long noteId);
    boolean deletePhoneBookNote(Long id);
    boolean deletePhoneBookNoteByUserIdAndPhoneBookId(Long id, Long phoneBookNoteId);
    boolean addPhoneBookNote(Long id, PhoneBookNote phoneBookNote);
    boolean updatePhoneBookNoteByUserIdAndId(Long id, Long noteId, String name, String phoneNumber);
    Iterable<PhoneBookNote> getPhoneBookNotesByPhoneNumber(String phoneNumber);
}
