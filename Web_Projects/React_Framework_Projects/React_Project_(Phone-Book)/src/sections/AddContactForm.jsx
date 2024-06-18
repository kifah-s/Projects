import {Button, Input, Spinner, Textarea} from "@nextui-org/react";
import {useState} from "react";
import axios from "axios";

const AddContactForm = ({onAdd}) => {
    const initialState = {
        name: "",
        phone: "",
        email: "",
        notes: "",
    };
    const [data, setData] = useState(initialState);
    const [loading, setLoading] = useState(false);
    const saveContact = () => {
        setLoading(true)
        axios.post("/api/contacts", data, {
            headers: {
                "Content-Type": "application/json"
            }
        })
            .then((r) => {
                if (onAdd) {
                    onAdd(r.data);
                }
                setData(initialState)
            })
            .catch((e) => {
            })
            .finally(() => {
                setLoading(false)
            })
    }

    return (
        <>
            <h5 className="mt-2 text-2xl text-gray-400">Add New Contact</h5>
            <Input className="mb-3 mt-3" placeholder="add name" value={data.name}
                   onChange={(e) => setData((prev) => ({...prev, name: e.target.value}))}/>
            <Input type="tel" className="mb-3 mt-3" placeholder="add phone" value={data.phone}
                   onChange={(e) => setData((prev) => ({...prev, phone: e.target.value}))}/>
            <Input type="email" className="mb-3 mt-3" placeholder="add e-mail" value={data.email}
                   onChange={(e) => setData((prev) => ({...prev, email: e.target.value}))}/>
            <Textarea minRows={10} maxRows={10} className="mb-3" placeholder="add some notes..." value={data.notes}
                      onChange={(e) => setData((prev) => ({...prev, notes: e.target.value}))}/>
            <Button disabled={loading} onClick={saveContact} color="primary" fullWidth>{ loading ? <Spinner /> : "Add" }</Button>
        </>
    );
};

export default AddContactForm;