package com.dins.phonebook.controller;

import com.dins.phonebook.domain.PhoneBookNote;
import com.dins.phonebook.exception.DuplicatePhoneNumber;
import com.dins.phonebook.service.PhoneBookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.hateoas.EntityModel;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

@Controller
@RequestMapping(path="/user/{id}")
public class UserPhoneBookController {

    @Autowired
    private PhoneBookService phoneBookService;

    @GetMapping(path="/notes")
    public @ResponseBody
    Iterable<PhoneBookNote> getNotes (@PathVariable Long id) {
        return phoneBookService.getUserPhoneBook(id);
    }

    @GetMapping(path="/note/{noteId}")
    public @ResponseBody
    EntityModel<PhoneBookNote> getNote (@PathVariable Long id, @PathVariable Long noteId) {
        return phoneBookService.getPhoneBookNoteByUserIdAndId(id, noteId);
    }

    @DeleteMapping(path="/delete-note")
    @ResponseStatus(HttpStatus.OK)
    public @ResponseBody
    void deleteNote (@PathVariable Long id, @RequestBody Map<String, Long> noteId) {
        phoneBookService.deletePhoneBookNoteByUserIdAndPhoneBookId(id, noteId.get("noteId"));
    }

    @PutMapping(path = "/note/{noteId}")
    @ResponseStatus(HttpStatus.OK)
    public @ResponseBody
    String updateNote(@PathVariable Long id, @PathVariable Long noteId,  @RequestBody PhoneBookNote phoneBookNote){
        phoneBookService.updatePhoneBookNoteByUserIdAndId(id, noteId,  phoneBookNote.getName(), phoneBookNote.getPhoneNumber());
        return "Updated";
    }

    @PostMapping(path="/add-note")
    @ResponseStatus(HttpStatus.CREATED)
    public @ResponseBody
    String addNote (@PathVariable Long id, @RequestBody PhoneBookNote phoneBookNote) {
        phoneBookService.addPhoneBookNote(id, phoneBookNote);
        return "Saved";
    }
}
