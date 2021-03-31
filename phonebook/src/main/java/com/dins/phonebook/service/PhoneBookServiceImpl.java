package com.dins.phonebook.service;

import com.dins.phonebook.controller.UserPhoneBookController;
import com.dins.phonebook.domain.PhoneBookNote;
import com.dins.phonebook.domain.User;
import com.dins.phonebook.exception.DuplicatePhoneNumber;
import com.dins.phonebook.exception.NoteNotFoundException;
import com.dins.phonebook.exception.UserNotFoundException;
import com.dins.phonebook.repository.PhoneBookRepository;
import com.dins.phonebook.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.hateoas.EntityModel;
import org.springframework.stereotype.Service;

import java.util.Optional;

import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.linkTo;
import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.methodOn;

@Service
@Qualifier("phoneBookService")
public class PhoneBookServiceImpl implements PhoneBookService{
    @Autowired
    private UserRepository userRepository;

    @Autowired
    private PhoneBookRepository phoneBookRepository;

    @Override
    public Optional<PhoneBookNote> getPhoneBookNoteById(Long id) {
        PhoneBookNote phoneBookNote = phoneBookRepository.findById(id).orElseThrow(()->new NoteNotFoundException(id));
        return Optional.ofNullable(phoneBookNote);
    }

    @Override
    public Iterable<PhoneBookNote> getUserPhoneBook(Long id) {
        Optional<User> user = userRepository.findById(id);
        user.orElseThrow(() -> new UserNotFoundException(id));
        return phoneBookRepository.findPhoneBookNotesByUserId(id);
    }

    @Override
    public EntityModel<PhoneBookNote> getPhoneBookNoteByUserIdAndId(Long id, Long noteId) {
        PhoneBookNote phoneBookNote = phoneBookRepository.findPhoneBookNoteByUserIdAndId(id, noteId)
                .orElseThrow(() -> new NoteNotFoundException(id));
        return EntityModel.of(phoneBookNote,
                linkTo(methodOn(UserPhoneBookController.class).getNote(id, noteId)).withSelfRel(),
                linkTo(methodOn(UserPhoneBookController.class).getNotes(id)).withRel("user_notes"));
    }

    @Override
    public boolean deletePhoneBookNote(Long id) {
        phoneBookRepository.deleteById(id);
        return true;
    }

    @Override
    public boolean deletePhoneBookNoteByUserIdAndPhoneBookId(Long id, Long phoneBookNoteId) {
        phoneBookRepository.deletePhoneBookNoteByUserIdAndId(id, phoneBookNoteId);
        return true;
    }

    @Override
    public boolean addPhoneBookNote(Long id, PhoneBookNote phoneBookNote) {
        phoneBookNote.setUser(userRepository.findById(id).get());
        try {
            phoneBookRepository.save(phoneBookNote);
        } catch (Exception e){
            throw new DuplicatePhoneNumber(phoneBookNote.getPhoneNumber());
        }
        return true;
    }

    @Override
    public boolean updatePhoneBookNoteByUserIdAndId(Long id, Long noteId, String name, String phoneNumber) {
        phoneBookRepository.updatePhoneBookNoteByUserIdAndId(id, noteId, name, phoneNumber);
        return true;
    }

    @Override
    public Iterable<PhoneBookNote> getPhoneBookNotesByPhoneNumber(String phoneNumber) {
        return phoneBookRepository.findPhoneBookNoteByPhoneNumber(phoneNumber);
    }
}
