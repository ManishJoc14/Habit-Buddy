import { createAsyncThunk } from "@reduxjs/toolkit";
import { add_Note, delete_Note, view_Note , check_Note, edit_Note } from "./apis";

export const addNoteAsync = createAsyncThunk(
  "notesManager/addNoteAsync",
  async ({ id, note, category, startDate, endDate, description, priority, done}, thunkAPI) => {
    try {
      const response = await add_Note({id, note, category, startDate, endDate, description, priority, done});
      // console.log(response.data);
      return response?.data; // object; note which was added  {id, note, category, startDate, endDate, description, priority, done}
    } catch (error) {
      return thunkAPI.rejectWithValue(error.response.data);
    }
  }
);

export const viewNoteAsync = createAsyncThunk(
  "notesManager/viewNoteAsync",
  async (thunkAPI) => {
    try {
      const response = await view_Note();
      return response.data; // array of notes obj [{id, note, category, startDate, endDate, description, priority, done}, ....]
    } catch (error) {
      return thunkAPI.rejectWithValue(error.response.data);
    }
  }
);

export const deleteNoteAsync = createAsyncThunk(
  "notesManager/deleteNoteAsync",
  async ({id},thunkAPI) => {
    try {
      const response = await delete_Note({id});
      return response?.data; //id 
    } catch (error) {
      return thunkAPI.rejectWithValue(error.response.data);
    }
  }
);

export const checkNoteAsync = createAsyncThunk(
  "notesManager/checkNoteAsync",
  async ({id, done},thunkAPI) => {
    try {
      const response = await check_Note({id, done});
      return response?.data; //id of note
    } catch (error) {
      return thunkAPI.rejectWithValue(error.response.data);
    }
  }
);

export const editNoteAsync = createAsyncThunk(
  "notesManager/editNoteAsync",
  async ({ id, note, category, startDate, endDate, description, priority, done}, thunkAPI) => {
    try {
      const response = await edit_Note({id, note, category, startDate, endDate, description, priority, done});
      return response?.data; // object; note which was edited  {id, note, category, startDate, endDate, description, priority, done}
    } catch (error) {
      return thunkAPI.rejectWithValue(error.response.data);
    }
  }
);
